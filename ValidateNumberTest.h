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
	CPPUNIT_TEST(TestIsInputNotEmptyAndDigitWithEmptyString);
	CPPUNIT_TEST(TestHasInputValidLengthWithValidInputs);
	CPPUNIT_TEST_FAIL(TestHasInputValidLengthWithUnvalidInputs);
	CPPUNIT_TEST_SUITE_END();

public:


protected:
	void TestHasInputOnlyDigitWithDigits();
	void TestHasInputOnlyDigitWithLetters();
	void TestIsInputNotEmptyAndDigitWithEmptyString();
	void TestHasInputValidLengthWithValidInputs();
	void TestHasInputValidLengthWithUnvalidInputs();
};

#endif /* VALIDATENUMBERTEST_H_ */
