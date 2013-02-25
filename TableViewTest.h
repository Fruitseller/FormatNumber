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
#include <mockcpp.h>

#include "TableView.h"

using namespace std;


class TableViewTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TableViewTest);
	CPPUNIT_TEST(TestPrintTableWithFalseParameter);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void TestPrintTableWithFalseParameter();
private:
	TableView* TableViewObj;
	mysqlpp::Connection* ConnectionTestObj;

};
#endif /* DBMANAGEMENTMENUTEST_H_ */
