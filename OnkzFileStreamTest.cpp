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
	TestFileStream = new OnkzFileStream();
}


void OnkzFileStreamTest::tearDown()
{
	delete TestFileStream;
}

void OnkzFileStreamTest::TestGetMapFromFileStream()
{

}

void OnkzFileStreamTest::TestFindCityNameFromMap()
{

}


