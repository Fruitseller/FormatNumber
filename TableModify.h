/*
 * TableModify.h
 *
 *  Created on: 02.04.2013
 *      Author: bronkalla
 */

#ifndef TABLEMODIFY_H_
#define TABLEMODIFY_H_

#include <iostream>
#include <string>
#include <mysql++.h>

#include "TableView.h"
#include "eDatabaseInsertion.h"

using namespace std;

class TableModify
{
public:
	/**
	 * If OwnConnection=true then delete mysqlpp::Connection
	 * When false then Object must be deleted in other place not here
	 */
	~TableModify();


	/**
	 * Constructor with no param set OwnConnection=true and create new mysqlpp::Connection object
	 *
	 */
	TableModify();


	/**
	 * When OwnConnection = true then delete first object and copy new object to DBConnection
	 *
	 *@param mysqlpp::Connection pointer
	 */
	void SetDBConnection(mysqlpp::Connection*);


	/**
	 *@return mysqlpp::Connection pointer DBConnection
	 */
	mysqlpp::Connection* GetDBConnection();


	bool InsertCountryCode(string, string);


	bool InsertAreaCode(string, string, string, string);


	bool IsStringInAreaCode(string);


	string GetIDFromInsertIntoAreaCode(string);


	bool IsStringInCity(string);


	string GetIDFromInsertIntoCity(string);


	string GetIDFromInsertIntoArea(string, string);


	bool InsertIntoAreaCountryCode(string, string);


	bool IsStringInCountryCode(string);


	bool InsertIntoCountryCode(string, string);


private:
	/**
	 * Is needed because of double delete problems with the Constructor and Destructor
	 */
	bool OwnConnection;

	/**
	 * DB Connection that is used in whole code
	 */
	mysqlpp::Connection* DBConnection;
};


#endif /* TABLEMODIFY_H_ */
