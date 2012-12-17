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
#include "PrefixContainer.h"

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
	CPPUNIT_TEST(TestNormalizePhoneNumber);
	CPPUNIT_TEST(TestExtractPrefixFromMapWithValidInput);
	CPPUNIT_TEST(TestExtractPrefixFromMapWithFalseInput);
	CPPUNIT_TEST(TestParsePhoneNumberWithValidInput);
	CPPUNIT_TEST(TestParsePhoneNumberWithFalseInput);
	CPPUNIT_TEST(TestEraseNotDigitFromPhoneNumber);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	/**
	 * Call FormatGlobalNumberToLocalNumber(). Write result in TestPhoneNumber and check Data of Obj for valid informations.
	 */
	void TestFormatGlobalNumberToLocalNumberWithValidNumber();


	/**
	 * Call FormatGlobalNumberToLocalNumber(). Write result in TestPhoneNumber and check if Obj == NULL.
	 */
	void TestFormatGlobalNumberToLocalNumberWithUnvalidNumber();


	/**
	 * Call GetCountryCodeFromGlobalNumber(). Check if returned result == expected result.
	 */
	void TestGetCountryCodeFromGlobalNumberWithValidGlobalNumber();


	/**
	 * Call GetAreaCodeFromGlobalNumber(). Check if returned result == expected result.
	 */
	void TestGetAreaCodeFromGlobalNumberWithValidGlobalNumber();


	/**
	 * Call GetNumberFromGlobalNumber(). Check if returned result == expected result.
	 */
	void TestGetNumberFromGlobalNumberWithValidGlobalNumber();


	/**
	 * Call GetCityNameFromGlobalNumber(). Check if returned result == expected result.
	 */
	void TestGetCityNameFromGlobalNumber();


	/**
	 * Call NormalizePhoneNumber(). Check if returned == expected result.
	 */
	void TestNormalizePhoneNumber();


	/**
	 * Call ExtractPrefixFromMap() with valid map. Check if Obj was created correctly.
	 */
	void TestExtractPrefixFromMapWithValidInput();


	/**
	 * Call ExtractPrefixFromMap with valid map. Check if method throw exception when Obj was not created correctly.
	 */
	void TestExtractPrefixFromMapWithFalseInput();


	/**
	 * Call ParsePhoneNumber(). Check if created Obj == expected Obj.
	 */
	void TestParsePhoneNumberWithValidInput();


	/**
	 * Call ParsePhoneNumber(). Check if method throw exception when Obj was not created correctly.
	 */
	void TestParsePhoneNumberWithFalseInput();


	/**
	 * Call EraseNotDigitFromPhoneNumber(). Check if returned result == expected result.
	 */
	void TestEraseNotDigitFromPhoneNumber();

private:
	PhoneNumber* TestPhoneNumber;
	FormatNumber* Formatter;
	PrefixContainer* TestPrefix;
};


#endif /* FORMATNUMBERTEST_H_ */
