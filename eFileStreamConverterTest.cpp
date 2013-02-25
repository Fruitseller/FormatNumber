/*
 * eFileStreamConverterTest.cpp
 *
 *  Created on: 08.01.2013
 *      Author: bronkalla
 */

#include "eFileStreamConverterTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(eFileStreamConverterTest);

void eFileStreamConverterTest::setUp()
{
	ConverterException = new eFileStreamConverter();
}


void eFileStreamConverterTest::tearDown()
{
	delete ConverterException;
}


void eFileStreamConverterTest::TestWhat()
{
	string output;
	output = ConverterException->what();
	string* lol = &output;
	CPPUNIT_ASSERT(typeid(output) == typeid(*lol));

}
