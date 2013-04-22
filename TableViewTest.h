/*
 * DBManagementMenuTest.h
 *
 *  Created on: 19.02.2013
 *      Author: bronkalla
 */

#ifndef DBMANAGEMENTMENUTEST_H_
#define DBMANAGEMENTMENUTEST_H_

#include <iostream>
#include <string>
#include <mysql++.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

//#include <mockcpp/mockcpp.h>
//#include <mockcpp/MockObject.h>
//#include <mockcpp/MockObjectHelper.h>

#include "TableView.h"

using namespace std;


class TableViewTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TableViewTest);
	CPPUNIT_TEST(TestGetDbConnection);
	CPPUNIT_TEST(TestSetDbConnectionAndIfConnectionWord);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	/**
	 * Call TableViewObj->GetDbConnection(). Call first TableViewObj->SetDbConnection() and then check if the object is the same
	 */
	void TestGetDbConnection();

	void TestSetDbConnectionAndIfConnectionWord();

private:
	TableView* TableViewObj;
	mysqlpp::Connection* ConnectionObj;
};
#endif /* DBMANAGEMENTMENUTEST_H_ */
