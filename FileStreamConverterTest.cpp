/*
 * OnkzFileStreamTest.cpp
 *
 *  Created on: 26.11.2012
 *      Author: bronkalla
 */

#include "FileStreamConverterTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(FileStreamConverterTest);


void FileStreamConverterTest::setUp()
{
	//Nothing
}


void FileStreamConverterTest::tearDown()
{
	//Nothing
}


void FileStreamConverterTest::TestGetMapFromFileDirectoryWithFalsePath()
{
	CPPUNIT_ASSERT_THROW(FileStreamConverter::GetMapFromFileDirectory("/home/FALSE"), eFileStreamConverter);
}


void FileStreamConverterTest::TestFindCityNameFromMapWithValidResult()
{
	map<string, string> onkzMapList;

	onkzMapList = FileStreamConverter::GetMapFromFileDirectory("/home/bronkalla/workspace/FormatNumber/src/onkz.txt");
	//valid onkz
	CPPUNIT_ASSERT(FileStreamConverter::FindCityNameFromMap(onkzMapList, "2131") == "Kaarst");
	//unvalid onkz
	CPPUNIT_ASSERT(FileStreamConverter::FindCityNameFromMap(onkzMapList, "424242") == "Keine passende Stadt gefunden!");
}


void FileStreamConverterTest::TestLoadCCMap()
{
	map<string, string> fileMap;

	fileMap = FileStreamConverter::LoadCCMap();
	CPPUNIT_ASSERT(fileMap["49"].compare("Germany") == 0);
}


void FileStreamConverterTest::TestLoadACMapFromCCWithValidInput()
{
	map<string, string> fileMap;

	fileMap = FileStreamConverter::LoadACMapFromCC("49");
	CPPUNIT_ASSERT(fileMap["211"].compare("Düsseldorf") == 0);
	fileMap = FileStreamConverter::LoadACMapFromCC("48");
	CPPUNIT_ASSERT(fileMap["666"].compare("deineMudda") == 0);
}


void FileStreamConverterTest::TestLoadACMapFromCCWithFalseInput()
{

	CPPUNIT_ASSERT_THROW(FileStreamConverter::LoadACMapFromCC("42"), eFileStreamConverter);

	CPPUNIT_ASSERT_THROW(FileStreamConverter::LoadACMapFromCC("9000"), eFileStreamConverter);

}
