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
	/**
	 * Called FormatGlobalNumberToLocalNumber(). Write result in TestPhoneNumber and check Data of Obj for valid informations.
	 */
	void TestFormatGlobalNumberToLocalNumberWithValidNumber();


	/**
	 * Called FormatGlobalNumberToLocalNumber(). Write result in TestPhoneNumber and check if Obj == NULL.
	 */
	void TestFormatGlobalNumberToLocalNumberWithUnvalidNumber();


	/**
	 * Called GetCountryCodeFromGlobalNumber(). Checked if returned result == expected result.
	 */
	void TestGetCountryCodeFromGlobalNumberWithValidGlobalNumber();


	/**
	 * Called GetAreaCodeFromGlobalNumber(). Checked if returned result == expected result.
	 */
	void TestGetAreaCodeFromGlobalNumberWithValidGlobalNumber();


	/**
	 * Called GetNumberFromGlobalNumber(). Checked if returned result == expected result.
	 */
	void TestGetNumberFromGlobalNumberWithValidGlobalNumber();

	/**
	 * Called GetCityNameFromGlobalNumber(). Checked if returned result == expected result.
	 */
	void TestGetCityNameFromGlobalNumber();

private:
	PhoneNumber* TestPhoneNumber;
	FormatNumber* Formatter;
};


#endif /* FORMATNUMBERTEST_H_ */
