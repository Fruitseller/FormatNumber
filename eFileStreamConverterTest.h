/*
 * eFileStreamConverterTest.h
 *
 *  Created on: 08.01.2013
 *      Author: bronkalla
 */

#ifndef EFILESTREAMCONVERTERTEST_H_
#define EFILESTREAMCONVERTERTEST_H_

#include <iostream>
#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "eFileStreamConverter.h"

using namespace std;

class eFileStreamConverterTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(eFileStreamConverterTest);
	CPPUNIT_TEST(TestWhat);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	/**
	 * Call What(). Check if return value == string.
	 */
	void TestWhat();

private:
	eFileStreamConverter* ConverterException;
};


#endif /* EFILESTREAMCONVERTERTEST_H_ */
