/*
 * FormatNumberTest.h
 *
 *  Created on: 20.11.2012
 *      Author: bronkalla
 */

#ifndef FORMATNUMBERTEST_H_
#define FORMATNUMBERTEST_H_


#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "FormatNumber.h"
#include "PhoneNumber.h"

using namespace std;


class FormatNumberTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(FormatNumberTest);
	CPPUNIT_TEST(TestFormatGlobalNumberToLocalNumberWithValidNumber);
	CPPUNIT_TEST(TestFormatGlobalNumberToLocalNumberWithUnvalidNumber);
	CPPUNIT_TEST(TestGetCountryCodeFromGlobalNumberWithValidGlobalNumber);
	CPPUNIT_TEST(TestGetAreaCodeFromGlobalNumberWithValidGlobalNumber);
	CPPUNIT_TEST(TestGetNumberFromGlobalNumberWithValidGlobalNumber);
	CPPUNIT_TEST(TestGetCityNameFromGlobalNumber);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void TestFormatGlobalNumberToLocalNumberWithValidNumber();
	void TestFormatGlobalNumberToLocalNumberWithUnvalidNumber();
	void TestGetCountryCodeFromGlobalNumberWithValidGlobalNumber();
	void TestGetAreaCodeFromGlobalNumberWithValidGlobalNumber();
	void TestGetNumberFromGlobalNumberWithValidGlobalNumber();
	void TestGetCityNameFromGlobalNumber();

private:
	PhoneNumber* TestPhoneNumber;
	FormatNumber* Formatter;
};


#endif /* FORMATNUMBERTEST_H_ */
