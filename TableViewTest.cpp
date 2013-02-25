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
	ConnectionTestObj = new mysqlpp::Connection(true);
}


void TableViewTest::tearDown()
{
	delete TableViewObj;
	delete ConnectionTestObj;
}


void TableViewTest::TestPrintTableWithFalseParameter()
{
	/**
	if (ConnectionTestObj->connect("test", "localhost","root", "", 3306))
	{

	}
	else
	{

	}
	*/

	ConnectionTestObj->connect("bla", "no", "user", "pw", 0000);

	TableViewObj->SetDbConnection(ConnectionTestObj);
	TableViewObj->DumpCityTable();
	//CPPUNIT_ASSERT_MESSAGE("Failed to get item list: MySQL server has gone away", TableViewObj->DumpCityTable());

	//ConnectionTestObj->connect("bla", "no", "user", "pw", 0000);
	//CPPUNIT_ASSERT_THROW(ConnectionTestObj->connect("bla", "no", "user", "pw", 0000), mysqlpp::Exception);
	//CPPUNIT_ASSERT_THROW(DBMenu->PrintTable(ConnectionTestObj, "whatever"), mysqlpp::Exception);
	//CPPUNIT_ASSERT_MESSAGE("Failed to get item list: MySQL server has gone away", DBMenu->PrintTable(ConnectionTestObj, "whatever"));
	//CPPUNIT_ASSERT_THROW(ConnectionTestObj->connect("bla", "no", "user", "pw", 0000), mysqlpp::ConnectionFailed);

}
