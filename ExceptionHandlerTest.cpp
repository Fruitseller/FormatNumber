/*
 * ExceptionHandlerTest.cpp
 *
 *  Created on: 08.01.2013
 *      Author: bronkalla
 */

#include "ExceptionHandlerTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ExceptionHandlerTest);

void ExceptionHandlerTest::setUp()
{
	ExceptionHelperObj = new ExceptionHandler();
}


void ExceptionHandlerTest::tearDown()
{
	delete ExceptionHelperObj;
}


void ExceptionHandlerTest::TestConstructorWithoutParameter()
{
	ExceptionHandler* TestObj = new ExceptionHandler();
	CPPUNIT_ASSERT(typeid(TestObj) == typeid(ExceptionHandler*));
	delete TestObj;
}


void ExceptionHandlerTest::TestConstructorWithParameter()
{
	exception Error;
	ExceptionHandler* TestObj = new ExceptionHandler(&Error);
	CPPUNIT_ASSERT(typeid(TestObj) == typeid(ExceptionHandler*));
	delete TestObj;
}


void ExceptionHandlerTest::TestConvertExceptionToeFormatNumber()
{
	eFormatNumber* FormatException;
	exception Error;
	FormatException = ExceptionHelperObj->ConvertExceptionToeFormatNumber(&Error);
	CPPUNIT_ASSERT(typeid(FormatException) == typeid(eFormatNumber*));
}


void ExceptionHandlerTest::TestConvertExceptionToeFileStreamConverter()
{
	eFileStreamConverter* ConverterException;
	exception Error;
	ConverterException = ExceptionHelperObj->ConvertExceptionToeFileStreamConverter(&Error);
	CPPUNIT_ASSERT(typeid(ConverterException) == typeid(eFileStreamConverter*));
}


void ExceptionHandlerTest::TestConvertExceptionToeFalseNumberLength()
{
	eFalseNumberLength* LengthException;
	exception Error;
	LengthException = ExceptionHelperObj->ConvertExceptionToeFalseNumberLength(&Error);
	CPPUNIT_ASSERT(typeid(LengthException) == typeid(eFalseNumberLength*));


}

