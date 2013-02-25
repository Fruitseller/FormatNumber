/*
 * TableView.h
 *
 *  Created on: 19.02.2013
 *      Author: bronkalla
 */

#ifndef TABLEVIEW_H_
#define TABLEVIEW_H_

#include <iostream>
#include <string>
#include <mysql++.h>

#include "FormatNumber.h"

using namespace std;

class TableView
{
public:
	void SetDbConnection(mysqlpp::Connection*);
	void DumpCityTable();
	void DumpAreaCodeTable();
	void DumpResultsForTableCity(mysqlpp::StoreQueryResult result);
	void DumpResultsForTableAreaCode(mysqlpp::StoreQueryResult result);

private:
	mysqlpp::Connection* dbConnection;
};

#endif /* TABLEVIEW_H_ */
