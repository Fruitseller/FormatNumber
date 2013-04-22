/*
 * TableView.cpp
 *
 *  Created on: 19.02.2013
 *      Author: bronkalla
 */

#include "TableView.h"


TableView::~TableView()
{
	if (this->OwnConnection) {
		delete this->dbConnection;
	}
}


TableView::TableView()
{
	OwnConnection = true;
	this->dbConnection = new mysqlpp::Connection(true);
}


void TableView::SetDbConnection(mysqlpp::Connection* Connection)
{
	if (this->OwnConnection)
	{
		delete this->dbConnection ;
		this->OwnConnection = false;
	}

	this->dbConnection = Connection;
}


mysqlpp::Connection* TableView::GetDbConnection()
{
	return this->dbConnection;
}


mysqlpp::StoreQueryResult TableView::DumpCityTable()
{
	string statement = "SELECT city_id, city FROM city";

	mysqlpp::Query query = this->dbConnection->query(statement);

	if (mysqlpp::StoreQueryResult result = query.store())
	{
		return result;
	}
	else
		throw eDatabaseInsertion();
}


mysqlpp::StoreQueryResult TableView::DumpAreaCodeTable()
{
	string statement = "SELECT area_code_id, area_code FROM area_code";

	mysqlpp::Query query = this->dbConnection->query(statement);

	if (mysqlpp::StoreQueryResult result = query.store())
	{
		return result;
	}
	else
		throw eDatabaseInsertion();
}


void TableView::DumpResultsForTableCity(mysqlpp::StoreQueryResult result)
{
	cout << "\nSchema:\n";
			cout << '\t' << "city" << "_id" << '\t' << "city" << endl << endl;
			mysqlpp::StoreQueryResult::const_iterator it;
			for (it = result.begin(); it != result.end(); ++it)
			{
				mysqlpp::Row row = *it;
				if(row.size() == 2)
				{
					cout << '\t' << row[0];
					cout << '\t' << row[1] << endl;
				}
			}
}


void TableView::DumpResultsForTableAreaCode(mysqlpp::StoreQueryResult result)
{
	cout << "\nSchema:\n";
			cout << '\t' << "area_code" << "_id" << '\t' << "area_code" << endl << endl;
			mysqlpp::StoreQueryResult::const_iterator it;
			for (it = result.begin(); it != result.end(); ++it)
			{
				mysqlpp::Row row = *it;
				if(row.size() == 2)
				{
					cout << '\t'  << row[0];
					cout << '\t' << '\t' << row[1] << endl;
				}
			}
}


mysqlpp::StoreQueryResult TableView::DumpArea()
{
	string statement = "SELECT area_id, area_code_id, city_id FROM area";

	mysqlpp::Query query = this->dbConnection->query(statement);

	if (mysqlpp::StoreQueryResult result = query.store())
	{
		return result;
	}
	else
		throw eDatabaseInsertion();

}


mysqlpp::StoreQueryResult TableView::DumpCountryCode()
{
	string statement = "SELECT country_code, country_name FROM country_code";

	mysqlpp::Query query = this->dbConnection->query(statement);

	if (mysqlpp::StoreQueryResult result = query.store())
	{
		return result;
	}
	else
		throw eDatabaseInsertion();

}


mysqlpp::StoreQueryResult TableView::DumpAreaCountryCode()
{
	string statement = "SELECT area_id, country_code FROM country_code";

	mysqlpp::Query query = this->dbConnection->query(statement);

	if (mysqlpp::StoreQueryResult result = query.store())
	{
		return result;
	}
	else
		throw eDatabaseInsertion();

}
