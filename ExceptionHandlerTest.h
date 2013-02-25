/*
 * ExceptionHandlerTest.h
 *
 *  Created on: 08.01.2013
 *      Author: bronkalla
 */

#ifndef EXCEPTIONHANDLERTEST_H_
#define EXCEPTIONHANDLERTEST_H_

#include <iostream>
#include <string>
#include <exception>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "ExceptionHandler.h"

using namespace std;

class ExceptionHandlerTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(ExceptionHandlerTest);
	CPPUNIT_TEST(TestConstructorWithoutParameter);
	CPPUNIT_TEST(TestConstructorWithParameter);
	CPPUNIT_TEST(TestConvertExceptionToeFormatNumber);
	CPPUNIT_TEST(TestConvertExceptionToeFileStreamConverter);
	CPPUNIT_TEST(TestConvertExceptionToeFalseNumberLength);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	/**
	 * Call Default Constructor. Check if object build succesfull.
	 */
	void TestConstructorWithoutParameter();


	/**
	 * Call Constructor(exception). Check if object build succesfull.
	 */
	void TestConstructorWithParameter();


	/**
	 * Call ConvertExceptionToeFormatNumber(exception). Check if returned value == eFormatNumber Object.
	 */
	void TestConvertExceptionToeFormatNumber();


	/**
	 * Call ConvertExceptionToeFileStreamConverter(exception). Check if returned value == eFileStreamConverter Object.
	 */
	void TestConvertExceptionToeFileStreamConverter();


	/**
	 * Call ConvertExceptionToeFalseNumberLength(exception). Check if returned value == eFalseNumberLength Object.
	 */
	void TestConvertExceptionToeFalseNumberLength();

private:
	ExceptionHandler* ExceptionHelperObj;
};


#endif /* EXCEPTIONHANDLERTEST_H_ */
