/*
 * TableView.cpp
 *
 *  Created on: 19.02.2013
 *      Author: bronkalla
 */

#include "TableView.h"


void TableView::SetDbConnection(mysqlpp::Connection* Connection)
{
	dbConnection = Connection;
}

void TableView::DumpCityTable()
{
	string statement = "SELECT city_id, city FROM city";

	mysqlpp::Query query = dbConnection->query(statement);

	if (mysqlpp::StoreQueryResult result = query.store())
	{
		DumpResultsForTableCity(result);
	}
	else
		cerr << "Failed to get item list: " << query.error() << endl;
}

void TableView::DumpAreaCodeTable()
{
	string statement = "SELECT area_code_id, area_code FROM area_code";

	mysqlpp::Query query = dbConnection->query(statement);

	if (mysqlpp::StoreQueryResult result = query.store())
	{
		DumpResultsForTableAreaCode(result);
	}
	else
		cerr << "Failed to get item list: " << query.error() << endl;
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

