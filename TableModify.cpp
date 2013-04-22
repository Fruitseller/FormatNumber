/*
 * TableModify.cpp
 *
 *  Created on: 02.04.2013
 *      Author: bronkalla
 */

#include "TableModify.h"


TableModify::~TableModify()
{
	if (this->OwnConnection) {
		delete this->DBConnection;
	}
}


TableModify::TableModify()
{
	OwnConnection = true;
	this->DBConnection = new mysqlpp::Connection(true);
}


void TableModify::SetDBConnection(mysqlpp::Connection* Connection)
{
	if (this->OwnConnection)
	{
		delete this->DBConnection;
		this->OwnConnection = false;
	}

	this->DBConnection = Connection;
}


mysqlpp::Connection* TableModify::GetDBConnection()
{
	return this->DBConnection;
}


bool TableModify::InsertCountryCode(string country_code, string country_name)
{
	if(!(IsStringInCountryCode(country_code)))
	{
		if(InsertIntoCountryCode(country_code, country_name))
		{
			return true;
		}
		else
		{
			throw eDatabaseInsertion();
		}
	}
	return true;
}


bool TableModify::InsertAreaCode(string area_code, string city, string country_code, string country_name)
{
	string area_code_id("0"), city_id("0"), area_id("0");

	if(!(IsStringInAreaCode(area_code)))
	{
		area_code_id = GetIDFromInsertIntoAreaCode(area_code);
	}
	if(!(IsStringInCity(city)))
	{
		city_id = GetIDFromInsertIntoCity(city);
	}

	if (area_code_id != "0" or city_id != "0")
		area_id = GetIDFromInsertIntoArea(area_code_id, city_id);

	cout << "Wo gehts wohl schief?\n";
	if(InsertCountryCode(country_code, country_name))
	{
		cout << "Wärmer\n";
		cout << area_code_id << " und " << city_id << endl;
		if(area_id != "0")
		{
			cout << "Noch wärmer\n";
			if(InsertIntoAreaCountryCode(area_id, country_code))
				return true;
		}
		/**
		else
			cout << "Werfe Exception\n";
			throw eDatabaseInsertion();
		*/
	}
	else
	{
		cout << "Wärmer2\n";
		cout << area_code_id << " und " << city_id << endl;
		if(area_id != "0")
		{
			cout << "Noch wärmer2\n";
			if(InsertIntoAreaCountryCode(area_id, country_code))
				return true;
		}
	}

	throw eDatabaseInsertion();

}


bool TableModify::IsStringInAreaCode(string area_code)
{
	mysqlpp::StoreQueryResult TableResult;
	TableView Viewer;
	Viewer.SetDbConnection(this->DBConnection);
	TableResult = Viewer.DumpAreaCodeTable();

	mysqlpp::StoreQueryResult::const_iterator it;

		for (it = TableResult.begin(); it != TableResult.end(); ++it)
		{
			mysqlpp::Row row = *it;
			if(row.size() == 2)
			{
				if(row[1] == area_code)
				{
					return true;
				}
			}
		}
		return false;
}


string TableModify::GetIDFromInsertIntoAreaCode(string area_code)
{
	mysqlpp::StoreQueryResult result;
	mysqlpp::SimpleResult SimpleResult;
	TableView Viewer;
	Viewer.SetDbConnection(this->DBConnection);

	mysqlpp::Query query = this->DBConnection->query("INSERT INTO area_code (area_code) VALUES (%0q)");
	query.parse();
	SimpleResult = query.execute(area_code);
		if(SimpleResult.rows() == 1)
		{
			result = Viewer.DumpAreaCodeTable();
			mysqlpp::StoreQueryResult::const_iterator it;

			for (it = result.begin(); it != result.end(); ++it)
			{
				mysqlpp::Row row = *it;
				if(row.size() == 2)
				{
					if(row[1] == area_code)
					{
						return (string) row[0];
					}
				}
			}
		}
		throw eDatabaseInsertion();
}


bool TableModify::IsStringInCity(string city)
{
	mysqlpp::StoreQueryResult TableResult;
	TableView Viewer;
	Viewer.SetDbConnection(this->DBConnection);
	TableResult = Viewer.DumpCityTable();

	mysqlpp::StoreQueryResult::const_iterator it;

		for (it = TableResult.begin(); it != TableResult.end(); ++it)
		{
			mysqlpp::Row row = *it;
			if(row.size() == 2)
			{
				if(row[1] == city)
				{
					return true;
				}
			}
		}
		return false;
}


string TableModify::GetIDFromInsertIntoCity(string city)
{
	mysqlpp::StoreQueryResult result;
	mysqlpp::SimpleResult SimpleResult;
	TableView Viewer;
	Viewer.SetDbConnection(this->DBConnection);

	mysqlpp::Query query = this->DBConnection->query("INSERT INTO city (city) VALUES (%0q)");
	query.parse();
	SimpleResult = query.execute(city);
		if(SimpleResult.rows() == 1)
		{
			result = Viewer.DumpCityTable();
			mysqlpp::StoreQueryResult::const_iterator it;

			for (it = result.begin(); it != result.end(); ++it)
			{
				mysqlpp::Row row = *it;
				if(row.size() == 2)
				{
					if(row[1] == city)
					{
						return (string) row[0];
					}
				}
			}
		}
		throw eDatabaseInsertion();
}


string TableModify::GetIDFromInsertIntoArea(string area_code_id, string city_id)
{
	mysqlpp::StoreQueryResult result;
	mysqlpp::SimpleResult SimpleResult;
	TableView Viewer;
	Viewer.SetDbConnection(this->DBConnection);

	mysqlpp::Query query = this->DBConnection->query("INSERT INTO area (area_code_id, city_id) VALUES (%0q, %1q)");
	query.parse();
	SimpleResult = query.execute(area_code_id, city_id);
	if(SimpleResult.rows() == 1)
	{
		result = Viewer.DumpArea();
		mysqlpp::StoreQueryResult::const_iterator it;

		for (it = result.begin(); it != result.end(); ++it)
		{
			mysqlpp::Row row = *it;
			if(row.size() == 3)
			{
				if(row[1] == area_code_id && row[2] == city_id)
				{
					return (string) row[0];
				}
			}
		}
	}
	throw eDatabaseInsertion();
}


bool TableModify::InsertIntoAreaCountryCode(string area_id, string country_code)
{
	mysqlpp::StoreQueryResult result;
	mysqlpp::SimpleResult SimpleResult;
	TableView Viewer;
	Viewer.SetDbConnection(this->DBConnection);

	mysqlpp::Query query = this->DBConnection->query("INSERT INTO area_country_code (area_id, country_code) VALUES (%0q, %1q)");
	query.parse();
	SimpleResult = query.execute(area_id, country_code);
	if(SimpleResult.rows() == 1)
	{
		return true;
	}
	else
		return false;
}


bool TableModify::IsStringInCountryCode(string country_code)
{
	mysqlpp::StoreQueryResult TableResult;
	TableView Viewer;
	Viewer.SetDbConnection(this->DBConnection);
	TableResult = Viewer.DumpCountryCode();

	mysqlpp::StoreQueryResult::const_iterator it;

		for (it = TableResult.begin(); it != TableResult.end(); ++it)
		{
			mysqlpp::Row row = *it;
			if(row.size() == 2)
			{
				if(row[0] == country_code)
				{
					return true;
				}
			}
		}
		return false;
}


bool TableModify::InsertIntoCountryCode(string country_code, string country_name)
{
	mysqlpp::StoreQueryResult result;
	mysqlpp::SimpleResult SimpleResult;
	TableView Viewer;
	Viewer.SetDbConnection(this->DBConnection);

	mysqlpp::Query query = this->DBConnection->query("INSERT INTO country_code (country_code, country_name) VALUES (%0q, %1q)");
	query.parse();
	SimpleResult = query.execute(country_code, country_name);
	if(SimpleResult.rows() == 1)
	{
		return true;
	}
	else
		return false;
}
