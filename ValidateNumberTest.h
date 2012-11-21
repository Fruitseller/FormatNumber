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
	CPPUNIT_TEST(TestHasInputOnlyDigitWithDigitsAndLetters);
	CPPUNIT_TEST(TestIsInputNotEmptyAndDigitWithEmptyString);
	CPPUNIT_TEST(TestHasInputValidLengthWithMultipleInputs);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();
protected:
	void TestHasInputOnlyDigitWithDigitsAndLetters();
	void TestIsInputNotEmptyAndDigitWithEmptyString();
	void TestHasInputValidLengthWithMultipleInputs();
};

#endif /* VALIDATENUMBERTEST_H_ */
