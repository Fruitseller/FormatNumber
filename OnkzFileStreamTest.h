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
	CPPUNIT_TEST_EXCEPTION(TestGetMapFromFileDirectory, eOnkzFileStream);
	CPPUNIT_TEST(TestFindCityNameFromMap);
	CPPUNIT_TEST_SUITE_END();

public:

protected:
	void TestGetMapFromFileDirectory();
	void TestFindCityNameFromMap();

private:

};




#endif /* ONKZFILESTREAMTEST_H_ */
