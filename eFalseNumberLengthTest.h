/*
 * eFalseNumberLengthTest.h
 *
 *  Created on: 14.01.2013
 *      Author: bronkalla
 */

#ifndef EFALSENUMBERLENGTHTEST_H_
#define EFALSENUMBERLENGTHTEST_H_

#include <iostream>
#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "eFalseNumberLength.h"

using namespace std;

class eFalseNumberLengthTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(eFalseNumberLengthTest);
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
	eFalseNumberLength* FalseNumberLengthException;
};


#endif /* EFALSENUMBERLENGTHTEST_H_ */
