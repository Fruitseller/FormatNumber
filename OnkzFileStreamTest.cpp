/*
 * OnkzFileStreamTest.cpp
 *
 *  Created on: 26.11.2012
 *      Author: bronkalla
 */

#include "OnkzFileStreamTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(OnkzFileStreamTest);


void OnkzFileStreamTest::TestGetMapFromFileDirectory()
{
	map<string, string> onkzMapList;

	CPPUNIT_ASSERT_THROW(onkzMapList = OnkzFileStream::GetMapFromFileDirectory("/home/bronkalla/workspace/FormatNumber/src/onkz.jpg")
						, eOnkzFileStream);
}

void OnkzFileStreamTest::TestFindCityNameFromMap()
{
	map<string, string> onkzMapList;

	onkzMapList = OnkzFileStream::GetMapFromFileDirectory("/home/bronkalla/workspace/FormatNumber/src/onkz.txt");
	//valid onkz
	CPPUNIT_ASSERT(OnkzFileStream::FindCityNameFromMap(onkzMapList, "02131") == "Kaarst");
	//unvalid onkz
	CPPUNIT_ASSERT(OnkzFileStream::FindCityNameFromMap(onkzMapList, "424242") == "Keine passende Stadt gefunden!");
}


