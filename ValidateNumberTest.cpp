/*
 * ValidateNumberTest.cpp
 *
 *  Created on: 21.11.2012
 *      Author: bronkalla
 */

#include "ValidateNumberTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ValidateNumberTest);


void ValidateNumberTest::setUp()
{
	//Nothing
}


void ValidateNumberTest::tearDown()
{
	//Nothing
}


void ValidateNumberTest::TestHasInputOnlyDigitWithDigits()
{
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("12345"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("12"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("123"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("1"));
}


void ValidateNumberTest::TestHasInputOnlyDigitWithLetters()
{
	//expected failure
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("arvbBUEcUDB"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("Ab"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("a"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("+"));

	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("A2B2d4uff"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("2aB5dz4tz7"));
}


void ValidateNumberTest::TestIsInputNotEmptyWithNotEmptyString()
{
	CPPUNIT_ASSERT(ValidateNumber::IsInputNotEmpty("32456"));
	CPPUNIT_ASSERT(ValidateNumber::IsInputNotEmpty("+"));
	CPPUNIT_ASSERT(ValidateNumber::IsInputNotEmpty("rtb"));
}


void ValidateNumberTest::TestIsInputNotEmptyWithEmptyString()
{
	CPPUNIT_ASSERT(ValidateNumber::IsInputNotEmpty(""));
}


void ValidateNumberTest::TestHasInputValidLengthWithValidInputs()
{
	//Given numbers are between 13 and 16 characters long
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength("0123456789ABC"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength("0123456789ABCD"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength("0123456789ABCDEF"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength("+123456789ABCDEF"));
}


void ValidateNumberTest::TestHasInputValidLengthWithUnvalidInputs()
{
	//Given numbers are too short and too long. Expect failure
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength("012345"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength("0123456789ABCDEFG"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength("+123456789ABCDEFG"));
}
