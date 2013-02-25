/*
 * eFormatNumberTest.h
 *
 *  Created on: 08.01.2013
 *      Author: bronkalla
 */

#ifndef EFORMATNUMBERTEST_H_
#define EFORMATNUMBERTEST_H_

#include <iostream>
#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "eFormatNumber.h"

class eFormatNumberTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(eFormatNumberTest);
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
	eFormatNumber* FormatException;
};


#endif /* EFORMATNUMBERTEST_H_ */
