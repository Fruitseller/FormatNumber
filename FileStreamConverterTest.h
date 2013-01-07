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

#include "FileStreamConverter.h"

using namespace std;

class FileStreamConverterTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(FileStreamConverterTest);
	CPPUNIT_TEST(TestGetMapFromFileDirectoryWithFalsePath);
	CPPUNIT_TEST(TestFindCityNameFromMapWithValidResult);
	CPPUNIT_TEST(TestLoadCCMap);
	CPPUNIT_TEST(TestLoadACMapFromCCWithValidInput);
	CPPUNIT_TEST(TestLoadACMapFromCCWithFalseInput);
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


	/**
	 * Call LoadCCMap(). Check for valid content in created map.
	 */
	void TestLoadCCMap();


	/**
	 * Call LoadACMapFromCC(). Check for valid content in created map which is based on valid input.
	 */
	void TestLoadACMapFromCCWithValidInput();


	/**
	 * Call LoadACMapFromCC(). Check if method throw exception when map can't be created.
	 */
	void TestLoadACMapFromCCWithFalseInput();
};




#endif /* ONKZFILESTREAMTEST_H_ */
