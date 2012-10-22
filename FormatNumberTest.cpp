#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>

#include "FormatNumber.h"

using namespace std;
using namespace CppUnit;

class FormatNumberTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(FormatNumberTest);
	CPPUNIT_TEST(TestIsInputNotEmptyAndDigitWithOnlyDigits);
	CPPUNIT_TEST(TestIsInputNotEmptyAndDigitWithOnlyLetters);
	CPPUNIT_TEST(TestIsInputNotEmptyAndDigitWithDigitsAndLetters);
	CPPUNIT_TEST(TestIsInputNotEmptyAndDigitWithEmptyString);
	CPPUNIT_TEST(TestFormatGlobalNumberToLocalNumberWithValidNumber);
	CPPUNIT_TEST(TestGetCountryCodeFromGlobalNumberWithValidGlobalNumber);
	CPPUNIT_TEST(TestGetAreaCodeFromGlobalNumberWithValidGlobalNumber);
	CPPUNIT_TEST(TestGetNumberFromGlobalNumberWithValidGlobalNumber);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void TestIsInputNotEmptyAndDigitWithOnlyDigits();
	void TestIsInputNotEmptyAndDigitWithOnlyLetters();
	void TestIsInputNotEmptyAndDigitWithDigitsAndLetters();
	void TestIsInputNotEmptyAndDigitWithEmptyString();
	void TestFormatGlobalNumberToLocalNumberWithValidNumber();
	void TestGetCountryCodeFromGlobalNumberWithValidGlobalNumber();
	void TestGetAreaCodeFromGlobalNumberWithValidGlobalNumber();
	void TestGetNumberFromGlobalNumberWithValidGlobalNumber();

private:
	FormatNumber *Formatter;
};

//---------------------------------------------------------------------------------------------------------------------

void FormatNumberTest::setUp()
{
	Formatter = new FormatNumber();
}

void FormatNumberTest::tearDown()
{
	delete Formatter;
}

void FormatNumberTest::TestIsInputNotEmptyAndDigitWithOnlyDigits()
{
	CPPUNIT_ASSERT(Formatter->IsInputNotEmptyAndDigit("12345"));
	CPPUNIT_ASSERT(Formatter->IsInputNotEmptyAndDigit("12"));
	CPPUNIT_ASSERT(Formatter->IsInputNotEmptyAndDigit("123"));
	CPPUNIT_ASSERT(Formatter->IsInputNotEmptyAndDigit("1"));
}

void FormatNumberTest::TestIsInputNotEmptyAndDigitWithOnlyLetters()
{
	CPPUNIT_ASSERT(!(Formatter->IsInputNotEmptyAndDigit("arvbBUEcUDB")));
	CPPUNIT_ASSERT(!(Formatter->IsInputNotEmptyAndDigit("Ab")));
	CPPUNIT_ASSERT(!(Formatter->IsInputNotEmptyAndDigit("a")));
}

void FormatNumberTest::TestIsInputNotEmptyAndDigitWithDigitsAndLetters()
{
	CPPUNIT_ASSERT(!(Formatter->IsInputNotEmptyAndDigit("A2B2d4uff")));
	CPPUNIT_ASSERT(!(Formatter->IsInputNotEmptyAndDigit("2aB5dz4tz7")));
}

void FormatNumberTest::TestIsInputNotEmptyAndDigitWithEmptyString()
{
	CPPUNIT_ASSERT(!(Formatter->IsInputNotEmptyAndDigit("")));
}

void FormatNumberTest::TestFormatGlobalNumberToLocalNumberWithValidNumber()
{
	string correctLocalNumber;
	correctLocalNumber = Formatter->FormatGlobalNumberToLocalNumber("00492111234567");
	CPPUNIT_ASSERT(correctLocalNumber.compare("02111234567") == 0);
	correctLocalNumber = Formatter->FormatGlobalNumberToLocalNumber("004921311513029");
	CPPUNIT_ASSERT(correctLocalNumber.compare("021311513029") == 0);
	correctLocalNumber = Formatter->FormatGlobalNumberToLocalNumber("0049307818820");
	CPPUNIT_ASSERT(correctLocalNumber.compare("0307818820") == 0);
}

void FormatNumberTest::TestGetCountryCodeFromGlobalNumberWithValidGlobalNumber()
{
	string correctCountryCode;
	correctCountryCode = Formatter->GetCountryCodeFromGlobalNumber("00492111234567");
	CPPUNIT_ASSERT(correctCountryCode.compare("0049") == 0);
	correctCountryCode = Formatter->GetCountryCodeFromGlobalNumber("004921311513029");
	CPPUNIT_ASSERT(correctCountryCode.compare("0049") == 0);
}

void FormatNumberTest::TestGetAreaCodeFromGlobalNumberWithValidGlobalNumber()
{
	string correctAreaCode;
	correctAreaCode = Formatter->GetAreaCodeFromGlobalNumber("00492111234567");
	CPPUNIT_ASSERT(correctAreaCode.compare("0211") == 0);
	correctAreaCode = Formatter->GetAreaCodeFromGlobalNumber("004921311513029");
	CPPUNIT_ASSERT(correctAreaCode.compare("02131") == 0);
	correctAreaCode = Formatter->GetAreaCodeFromGlobalNumber("0049307818820");
	CPPUNIT_ASSERT(correctAreaCode.compare("030") == 0);
}

void FormatNumberTest::TestGetNumberFromGlobalNumberWithValidGlobalNumber()
{
	string correctNumber;
	correctNumber = Formatter->GetNumberFromGlobalNumber("00492111234567");
	CPPUNIT_ASSERT(correctNumber.compare("1234567") == 0);
	correctNumber = Formatter->GetNumberFromGlobalNumber("004921311513029");
	CPPUNIT_ASSERT(correctNumber.compare("1513029") == 0);
	correctNumber = Formatter->GetNumberFromGlobalNumber("0049307818820");
	CPPUNIT_ASSERT(correctNumber.compare("7818820") == 0);
}

//---------------------------------------------------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION(FormatNumberTest);

int main(int argc, char* argv[])
{
	// informs test-listener about testresults
	CPPUNIT_NS::TestResult testresult;

	// register listener for collecting the test-results
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener (&collectedresults);

	// register listener for per-test progress output
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener (&progress);

	// insert test-suite at test-runner by registry
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
	testrunner.run(testresult);

	// output results in compiler-format
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	compileroutputter.write ();

	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}

