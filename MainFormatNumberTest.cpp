/*
 * MainFormatNumberTest.cpp
 *
 *  Created on: 20.11.2012
 *      Author: bronkalla
 */

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>

#include "FormatNumberTest.h"

int main(int argc, char* argv[])
{
	/* Test-Runner erzeugen */
	CppUnit::TextTestRunner runner;


	/* TestSuite erzeugen */
	CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();


	runner.addTest( suite );


	/* Outputformatierung festlegen */
	runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(), std::cerr ) );


	/* Tests durchführen
	** und 0 oder im Fehlerfall 1 zurückmelden */
	return runner.run() ? 0 : 1;
}


