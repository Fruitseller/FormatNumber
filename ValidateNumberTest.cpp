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
	TestPhoneNumber = new PhoneNumber();
	Formatter = new FormatNumber();
}


void ValidateNumberTest::tearDown()
{
	delete TestPhoneNumber;
	delete Formatter;
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
	//Given numbers are under 16 characters long
	TestPhoneNumber = Formatter->ParsePhoneNumber("0049211123456789");
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength(TestPhoneNumber));
	TestPhoneNumber = Formatter->ParsePhoneNumber("00492111234567899");
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength(TestPhoneNumber));
	TestPhoneNumber = Formatter->ParsePhoneNumber("+49211123456789");
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength(TestPhoneNumber));
	TestPhoneNumber = Formatter->ParsePhoneNumber("+492111234567899");
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength(TestPhoneNumber));
}


void ValidateNumberTest::TestHasInputValidLengthWithUnvalidInputs()
{
	//Given numbers are too long. Expect exception
	TestPhoneNumber = Formatter->ParsePhoneNumber("004921112345678999");
	CPPUNIT_ASSERT_THROW(ValidateNumber::HasInputValidLength(TestPhoneNumber), eFalseNumberLength);
	TestPhoneNumber = Formatter->ParsePhoneNumber("+4921112345678999");
	CPPUNIT_ASSERT_THROW(ValidateNumber::HasInputValidLength(TestPhoneNumber), eFalseNumberLength);
}


void ValidateNumberTest::TestIsInputValidSymbolWithValidChar()
{
	CPPUNIT_ASSERT(ValidateNumber::IsInputValidSymbol('('));
	CPPUNIT_ASSERT(ValidateNumber::IsInputValidSymbol(')'));
	CPPUNIT_ASSERT(ValidateNumber::IsInputValidSymbol('-'));
}


void ValidateNumberTest::TestIsInputValidSymbolWithFalseChar()
{
	CPPUNIT_ASSERT(ValidateNumber::IsInputValidSymbol('a'));
	CPPUNIT_ASSERT(ValidateNumber::IsInputValidSymbol('A'));
	CPPUNIT_ASSERT(ValidateNumber::IsInputValidSymbol('1'));
}


void ValidateNumberTest::TestIsInputInMapWithPossibleResult()
{
	map<string, string> fileMap;

	fileMap = FileStreamConverter::LoadCCMap();
	CPPUNIT_ASSERT(ValidateNumber::IsInputInMap(fileMap, "49"));
	CPPUNIT_ASSERT(ValidateNumber::IsInputInMap(fileMap, "48"));
}


void ValidateNumberTest::TestIsInputInMapWithFalseResult()
{
	map<string, string> fileMap;

	fileMap = FileStreamConverter::LoadCCMap();
	CPPUNIT_ASSERT(ValidateNumber::IsInputInMap(fileMap, "42"));
	CPPUNIT_ASSERT(ValidateNumber::IsInputInMap(fileMap, "9000"));
}


void ValidateNumberTest::TestIsInputDigitWithDigit()
{
	CPPUNIT_ASSERT(ValidateNumber::IsInputDigit('0'));
	CPPUNIT_ASSERT(ValidateNumber::IsInputDigit('1'));
	CPPUNIT_ASSERT(ValidateNumber::IsInputDigit('2'));
}


void ValidateNumberTest::TestIsInputDigitWithNotDigit()
{
	CPPUNIT_ASSERT(ValidateNumber::IsInputDigit('a'));
	CPPUNIT_ASSERT(ValidateNumber::IsInputDigit('A'));
	CPPUNIT_ASSERT(ValidateNumber::IsInputDigit('2'));
}
