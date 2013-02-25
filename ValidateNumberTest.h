/*
 * ValidateNumberTest.h
 *
 *  Created on: 21.11.2012
 *      Author: bronkalla
 */

#ifndef VALIDATENUMBERTEST_H_
#define VALIDATENUMBERTEST_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ValidateNumber.h"
#include "FileStreamConverter.h"
#include "FormatNumber.h"
#include "PhoneNumber.h"
#include "eFalseNumberLength.h"

using namespace std;

class ValidateNumberTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(ValidateNumberTest);
	CPPUNIT_TEST(TestHasInputOnlyDigitWithDigits);
	CPPUNIT_TEST_FAIL(TestHasInputOnlyDigitWithLetters);
	CPPUNIT_TEST(TestIsInputNotEmptyWithNotEmptyString);
	CPPUNIT_TEST_FAIL(TestIsInputNotEmptyWithEmptyString);
	CPPUNIT_TEST(TestHasInputValidLengthWithValidInputs);
	CPPUNIT_TEST(TestHasInputValidLengthWithUnvalidInputs);
	CPPUNIT_TEST(TestIsInputValidSymbolWithValidChar);
	CPPUNIT_TEST_FAIL(TestIsInputValidSymbolWithFalseChar);
	CPPUNIT_TEST(TestIsInputInMapWithPossibleResult);
	CPPUNIT_TEST_FAIL(TestIsInputInMapWithFalseResult);
	CPPUNIT_TEST(TestIsInputDigitWithDigit);
	CPPUNIT_TEST_FAIL(TestIsInputDigitWithNotDigit);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	/**
	 * Call HasInputOnlyDigit(). Expect TRUE because inputs are only digits.
	 */
	void TestHasInputOnlyDigitWithDigits();


	/**
	 * Call HasInputOnlyDigit(). Expect FALSE because inputs are only digits.
	 */
	void TestHasInputOnlyDigitWithLetters();


	/**
	 * Call IsInputNotEmpty(). Expect TRUE because inputs are not empty.
	 */
	void TestIsInputNotEmptyWithNotEmptyString();


	/**
	 * Call IsInputNotEmpty(). Expect FALSE because input is an empty string.
	 */
	void TestIsInputNotEmptyWithEmptyString();


	/**
	 * Call HasInputValidLength(). Expect TRUE because input has valid length.
	 */
	void TestHasInputValidLengthWithValidInputs();


	/**
	 * Call HasInputValidLength(). Expect FALSE because input has too long/short length.
	 */
	void TestHasInputValidLengthWithUnvalidInputs();


	/**
	 * Call IsInputValidSymbol(). Expect TRUE because input is a valid char.
	 */
	void TestIsInputValidSymbolWithValidChar();


	/**
	 * Call IsInputValidSymbol(). Expect FALSE because input isn't a valid char.
	 */
	void TestIsInputValidSymbolWithFalseChar();


	/**
	 * Call IsInputInMap() with valid map. Expect TRUE because given input is in given map.
	 */
	void TestIsInputInMapWithPossibleResult();


	/**
	 * Call IsInputInMapWith() with valid map. Expect FALSE because given input can't be found in given map.
	 */
	void TestIsInputInMapWithFalseResult();


	/**
	 * Call IsInputDigit(). Expect TRUE because input is a digit.
	 */
	void TestIsInputDigitWithDigit();


	/**
	 * Call IsInputDigit(). Expect FALSE because input isn't a digit.
	 */
	void TestIsInputDigitWithNotDigit();

private:
	PhoneNumber* TestPhoneNumber;
	FormatNumber* Formatter;
};

#endif /* VALIDATENUMBERTEST_H_ */
