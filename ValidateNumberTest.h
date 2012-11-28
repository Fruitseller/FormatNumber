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

using namespace std;

class ValidateNumberTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(ValidateNumberTest);
	CPPUNIT_TEST(TestHasInputOnlyDigitWithDigits);
	CPPUNIT_TEST_FAIL(TestHasInputOnlyDigitWithLetters);
	CPPUNIT_TEST(TestIsInputNotEmptyWithNotEmptyString);
	CPPUNIT_TEST_FAIL(TestIsInputNotEmptyWithEmptyString);
	CPPUNIT_TEST(TestHasInputValidLengthWithValidInputs);
	CPPUNIT_TEST_FAIL(TestHasInputValidLengthWithUnvalidInputs);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	/**
	 * Called HasInputOnlyDigit(). Expected TRUE because inputs are only digits.
	 */
	void TestHasInputOnlyDigitWithDigits();


	/**
	 * Called HasInputOnlyDigit(). Expected FALSE because inputs are only digits.
	 */
	void TestHasInputOnlyDigitWithLetters();


	/**
	 * Called IsInputNotEmpty(). Expected TRUE because inputs are not empty.
	 */
	void TestIsInputNotEmptyWithNotEmptyString();


	/**
	 * Called IsInputNotEmpty(). Expected FALSE because input is an empty string.
	 */
	void TestIsInputNotEmptyWithEmptyString();


	/**
	 * Called HasInputValidLength(). Expected TRUE because input has valid length.
	 */
	void TestHasInputValidLengthWithValidInputs();


	/**
	 * Called HasInputValidLength(). Expected FALSE because input has too long/short length.
	 */
	void TestHasInputValidLengthWithUnvalidInputs();
};

#endif /* VALIDATENUMBERTEST_H_ */
