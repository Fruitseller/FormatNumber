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
#include "eDatabaseInsertion.h"

using namespace std;

class TableView
{
public:
	/**
	 * If OwnConnection=true then delete mysqlpp::Connection
	 * When false then Object must be deleted in other place not here
	 */
	~TableView();


	/**
	 * Constructor with no param set OwnConnection=true and create new mysqlpp::Connection object
	 *
	 */
	TableView();


	/**
	 * When OwnConnection = true then delete first object and copy new object to dbConnection
	 *
	 *@param mysqlpp::Connection pointer
	 */
	void SetDbConnection(mysqlpp::Connection*);


	/**
	 *@return mysqlpp::Connection pointer dbConnection
	 */
	mysqlpp::Connection* GetDbConnection();


	/**
	 * Create a StoreQueryResult object that contains the result with all data of City Table
	 */
	mysqlpp::StoreQueryResult DumpCityTable();


	/**
	 * Create a StoreQueryResult object that contains the result with all data of AreaCode Table
	 */
	mysqlpp::StoreQueryResult DumpAreaCodeTable();


	/**
	 * Print out the content of the StoreQueryResult object
	 *
	 *@param mysqlpp::StoreQueryResult that is created in DumpCityTable()
	 */
	void DumpResultsForTableCity(mysqlpp::StoreQueryResult);


	/**
	 * Print out the content of the StoreQueryResult object
	 *
	 *@param mysqlpp::StoreQueryResult that is created in DumpAreaCodeTable()
	 */
	void DumpResultsForTableAreaCode(mysqlpp::StoreQueryResult);


	mysqlpp::StoreQueryResult DumpArea();


	mysqlpp::StoreQueryResult DumpCountryCode();


	mysqlpp::StoreQueryResult DumpAreaCountryCode();

private:
	/**
	 * Is needed because of double delete problems with the Constructor and Destructor
	 */
	bool OwnConnection;


	/**
	 * DB Connection that is used in whole code
	 */
	mysqlpp::Connection* dbConnection;
};

#endif /* TABLEVIEW_H_ */
