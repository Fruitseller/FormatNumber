/*
 * eFormatNumberTest.cpp
 *
 *  Created on: 08.01.2013
 *      Author: bronkalla
 */

#include "eFormatNumberTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(eFormatNumberTest);

void eFormatNumberTest::setUp()
{
	FormatException = new eFormatNumber();
}


void eFormatNumberTest::tearDown()
{
	delete FormatException;
}


void eFormatNumberTest::TestWhat()
{
	string output;
	output = FormatException->what();
	string* lol = &output;
	CPPUNIT_ASSERT(typeid(output) == typeid(*lol));
}


