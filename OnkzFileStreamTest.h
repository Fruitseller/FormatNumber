/*
 * OnkzFileStreamTest.h
 *
 *  Created on: 26.11.2012
 *      Author: bronkalla
 */

#ifndef ONKZFILESTREAMTEST_H_
#define ONKZFILESTREAMTEST_H_


#include <iostream>
#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "OnkzFileStream.h"

using namespace std;

class OnkzFileStreamTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(OnkzFileStreamTest);
	CPPUNIT_TEST(TestGetMapFromFileDirectoryWithFalsePath);
	CPPUNIT_TEST(TestFindCityNameFromMapWithValidResult);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	/**
	 * Called GetMapFromFileDirectory() and expected method throw eOnkzFileStream exception.
	 */
	void TestGetMapFromFileDirectoryWithFalsePath();


	/**
	 * Called FindCityNameFromMap(). Checked if find string is same as expected.
	 */
	void TestFindCityNameFromMapWithValidResult();
};




#endif /* ONKZFILESTREAMTEST_H_ */
