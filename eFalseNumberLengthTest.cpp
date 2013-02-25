/*
 * eFalseNumberLengthTest.cpp
 *
 *  Created on: 14.01.2013
 *      Author: bronkalla
 */

#include "eFalseNumberLengthTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(eFalseNumberLengthTest);

void eFalseNumberLengthTest::setUp()
{
	FalseNumberLengthException = new eFalseNumberLength();
}


void eFalseNumberLengthTest::tearDown()
{
	delete FalseNumberLengthException;
}


void eFalseNumberLengthTest::TestWhat()
{
	string output;
	output = FalseNumberLengthException->what();
	string* lol = &output;
	CPPUNIT_ASSERT(typeid(output) == typeid(*lol));
}
