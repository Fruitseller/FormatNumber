/*
 * OnkzFileStreamTest.cpp
 *
 *  Created on: 26.11.2012
 *      Author: bronkalla
 */

#include "OnkzFileStreamTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(OnkzFileStreamTest);


void OnkzFileStreamTest::setUp()
{
	//Nothing
}


void OnkzFileStreamTest::tearDown()
{
	//Nothing
}


void OnkzFileStreamTest::TestGetMapFromFileDirectoryWithFalsePath()
{
	CPPUNIT_ASSERT_THROW(OnkzFileStream::GetMapFromFileDirectory("/home/FALSE"), eOnkzFileStream);
}


void OnkzFileStreamTest::TestFindCityNameFromMapWithValidResult()
{
	map<string, string> onkzMapList;

	onkzMapList = OnkzFileStream::GetMapFromFileDirectory("/home/bronkalla/workspace/FormatNumber/src/onkz.txt");
	//valid onkz
	CPPUNIT_ASSERT(OnkzFileStream::FindCityNameFromMap(onkzMapList, "2131") == "Kaarst");
	//unvalid onkz
	CPPUNIT_ASSERT(OnkzFileStream::FindCityNameFromMap(onkzMapList, "424242") == "Keine passende Stadt gefunden!");
}


void OnkzFileStreamTest::TestLoadCCMap()
{
	map<string, string> fileMap;

	fileMap = OnkzFileStream::LoadCCMap();
	CPPUNIT_ASSERT(fileMap["49"].compare("Germany") == 0);
}


void OnkzFileStreamTest::TestLoadACMapFromCCWithValidInput()
{
	map<string, string> fileMap;

	fileMap = OnkzFileStream::LoadACMapFromCC("49");
	CPPUNIT_ASSERT(fileMap["211"].compare("Düsseldorf") == 0);
	fileMap = OnkzFileStream::LoadACMapFromCC("48");
	CPPUNIT_ASSERT(fileMap["666"].compare("deineMudda") == 0);
}


void OnkzFileStreamTest::TestLoadACMapFromCCWithFalseInput()
{

	CPPUNIT_ASSERT_THROW(OnkzFileStream::LoadACMapFromCC("42"), eOnkzFileStream);

	CPPUNIT_ASSERT_THROW(OnkzFileStream::LoadACMapFromCC("9000"), eOnkzFileStream);

}
