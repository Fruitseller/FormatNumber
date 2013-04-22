/*
 * DBManagementMenuTest.cpp
 *
 *  Created on: 19.02.2013
 *      Author: bronkalla
 */

#include "TableViewTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TableViewTest);

void TableViewTest::setUp()
{
	TableViewObj = new TableView();
	ConnectionObj = new mysqlpp::Connection(true);
}


void TableViewTest::tearDown()
{
	delete TableViewObj;
	delete ConnectionObj;
}


void TableViewTest::TestGetDbConnection()
{

	if (ConnectionObj->connect("test", "localhost","root", "", 3306))
	{
		TableViewObj->SetDbConnection(ConnectionObj);

		/**
		 * Debug informations
		 */
//		cout << endl << "Pointer address of ConnectionObj:                   " << ConnectionObj << endl;
//		cout << "Pointer address of TableViewObj->GetDbConnection(): " << TableViewObj->GetDbConnection() << endl;
//		cout << "ConnectionObj ping result: " << ConnectionObj->ping() << endl;
//		cout << "ConnectionObj connected: " << ConnectionObj->connected() << endl;
//		cout << "TableViewObj->GetDbConnection() ping result: " << TableViewObj->GetDbConnection()->ping() << endl;
//		cout << "TableViewObj->GetDbConnection() connected: " << TableViewObj->GetDbConnection()->connected() << endl;

		CPPUNIT_ASSERT(TableViewObj->GetDbConnection() == ConnectionObj);
	}
	else
	{
		CPPUNIT_ASSERT(false);
	}
}


void TableViewTest::TestSetDbConnectionAndIfConnectionWord()
{

	if (ConnectionObj->connect("test", "localhost","root", "", 3306))
	{
		TableViewObj->SetDbConnection(ConnectionObj);

		CPPUNIT_ASSERT(TableViewObj->GetDbConnection()->connected() == true);
	}
	else
	{
		CPPUNIT_ASSERT(false);
	}
}
