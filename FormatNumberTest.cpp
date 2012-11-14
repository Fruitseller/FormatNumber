#include <iostream>
#include <string>
#include <algorithm>
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
#include "ValidateNumber.h"
#include "PhoneNumber.h"

using namespace std;
using namespace CppUnit;

class FormatNumberTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(FormatNumberTest);
	CPPUNIT_TEST(TestHasInputOnlyDigitWithDigitsAndLetters);
	CPPUNIT_TEST(TestIsInputNotEmptyAndDigitWithEmptyString);
	CPPUNIT_TEST(TestHasInputValidLengthWithMultipleInputs);
	CPPUNIT_TEST(TestPhoneNumberWithValidNumbers);
	CPPUNIT_TEST(TestFormatGlobalNumberToLocalNumberWithValidNumber);
	CPPUNIT_TEST(TestFormatGlobalNumberToLocalNumberWithUnvalidNumber);
	CPPUNIT_TEST(TestGetCountryCodeFromGlobalNumberWithValidGlobalNumber);
	CPPUNIT_TEST(TestGetAreaCodeFromGlobalNumberWithValidGlobalNumber);
	CPPUNIT_TEST(TestGetNumberFromGlobalNumberWithValidGlobalNumber);
	CPPUNIT_TEST(TestGetCityNameFromGlobalNumber);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void TestHasInputOnlyDigitWithDigitsAndLetters();
	void TestIsInputNotEmptyAndDigitWithEmptyString();
	void TestHasInputValidLengthWithMultipleInputs();
	void TestPhoneNumberWithValidNumbers();
	void TestFormatGlobalNumberToLocalNumberWithValidNumber();
	void TestFormatGlobalNumberToLocalNumberWithUnvalidNumber();
	void TestGetCountryCodeFromGlobalNumberWithValidGlobalNumber();
	void TestGetAreaCodeFromGlobalNumberWithValidGlobalNumber();
	void TestGetNumberFromGlobalNumberWithValidGlobalNumber();
	void TestGetCityNameFromGlobalNumber();

private:
	PhoneNumber* TestPhoneNumber;
	FormatNumber* Formatter;
};

//---------------------------------------------------------------------------------------------------------------------

void FormatNumberTest::setUp()
{
	TestPhoneNumber = new PhoneNumber();
	Formatter = new FormatNumber();
}


void FormatNumberTest::tearDown()
{
	delete TestPhoneNumber;
	delete Formatter;
}


void FormatNumberTest::TestHasInputOnlyDigitWithDigitsAndLetters()
{
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("12345"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("12"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("123"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputOnlyDigits("1"));

	CPPUNIT_ASSERT(!(ValidateNumber::HasInputOnlyDigits("arvbBUEcUDB")));
	CPPUNIT_ASSERT(!(ValidateNumber::HasInputOnlyDigits("Ab")));
	CPPUNIT_ASSERT(!(ValidateNumber::HasInputOnlyDigits("a")));
	CPPUNIT_ASSERT(!(ValidateNumber::HasInputOnlyDigits("+")));

	CPPUNIT_ASSERT(!(ValidateNumber::HasInputOnlyDigits("A2B2d4uff")));
	CPPUNIT_ASSERT(!(ValidateNumber::HasInputOnlyDigits("2aB5dz4tz7")));
}


void FormatNumberTest::TestIsInputNotEmptyAndDigitWithEmptyString()
{
	CPPUNIT_ASSERT(!(ValidateNumber::IsInputNotEmpty("")));
	CPPUNIT_ASSERT(ValidateNumber::IsInputNotEmpty("32456"));
	CPPUNIT_ASSERT(ValidateNumber::IsInputNotEmpty("+"));
}


void FormatNumberTest::TestHasInputValidLengthWithMultipleInputs()
{
	//Given numbers are between 13 and 16 characters long
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength("0123456789ABC"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength("0123456789ABCD"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength("0123456789ABCDEF"));
	CPPUNIT_ASSERT(ValidateNumber::HasInputValidLength("+123456789ABCDEF"));
	//Given numbers are too short and too long. Expect fail
	CPPUNIT_ASSERT(!(ValidateNumber::HasInputValidLength("012345")));
	CPPUNIT_ASSERT(!(ValidateNumber::HasInputValidLength("0123456789ABCDEFG")));
	CPPUNIT_ASSERT(!(ValidateNumber::HasInputValidLength("+123456789ABCDEFG")));
}


void FormatNumberTest::TestPhoneNumberWithValidNumbers()
{
	TestPhoneNumber->SetGlobalNumber("00492111234567");
	CPPUNIT_ASSERT(TestPhoneNumber->GetGlobalNumber() == "00492111234567");
	TestPhoneNumber->SetLocalNumber("02111234567");
	CPPUNIT_ASSERT(TestPhoneNumber->GetLocalNumber() == "02111234567");
	TestPhoneNumber->SetCountryCode("0049");
	CPPUNIT_ASSERT(TestPhoneNumber->GetCountryCode() == "0049");
	TestPhoneNumber->SetAreaCode("0211");
	CPPUNIT_ASSERT(TestPhoneNumber->GetAreaCode() == "0211");
	TestPhoneNumber->SetNumber("1234567");
	CPPUNIT_ASSERT(TestPhoneNumber->GetNumber() == "1234567");
	TestPhoneNumber->SetNumber("Kaarst");
	CPPUNIT_ASSERT(TestPhoneNumber->GetNumber() == "Kaarst");

}


void FormatNumberTest::TestFormatGlobalNumberToLocalNumberWithValidNumber()
{
	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("00492111234567");
	CPPUNIT_ASSERT(TestPhoneNumber->GetLocalNumber().compare("02111234567") == 0);
	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("004921311513029");
	CPPUNIT_ASSERT(TestPhoneNumber->GetLocalNumber().compare("021311513029") == 0);
	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("0049307818820");
	CPPUNIT_ASSERT(TestPhoneNumber->GetLocalNumber().compare("0307818820") == 0);

	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("+49307818820");
	CPPUNIT_ASSERT(TestPhoneNumber->GetLocalNumber().compare("0307818820") == 0);
	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("+4921311513029");
	CPPUNIT_ASSERT(TestPhoneNumber->GetLocalNumber().compare("021311513029") == 0);

	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("+49307818820");
	CPPUNIT_ASSERT(TestPhoneNumber->GetCityName().compare("Berlin") == 0);
	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("004921311513029");
	CPPUNIT_ASSERT(TestPhoneNumber->GetCityName().compare("Kaarst") == 0);

}


void FormatNumberTest::TestFormatGlobalNumberToLocalNumberWithUnvalidNumber()
{
	CPPUNIT_ASSERT(Formatter->FormatGlobalNumberToLocalNumber("00492134g3g11234567") == NULL);
	CPPUNIT_ASSERT(Formatter->FormatGlobalNumberToLocalNumber("0049(0211)1234567") == NULL);
	CPPUNIT_ASSERT(Formatter->FormatGlobalNumberToLocalNumber("+49 (0211) 1234567") == NULL);
}


void FormatNumberTest::TestGetCountryCodeFromGlobalNumberWithValidGlobalNumber()
{
	string correctCountryCode;
	correctCountryCode = Formatter->GetCountryCodeFromGlobalNumber("00492111234567");
	CPPUNIT_ASSERT(correctCountryCode.compare("0049") == 0);
	correctCountryCode = Formatter->GetCountryCodeFromGlobalNumber("004921311513029");
	CPPUNIT_ASSERT(correctCountryCode.compare("0049") == 0);
	correctCountryCode = Formatter->GetCountryCodeFromGlobalNumber("+4921311513029");
	CPPUNIT_ASSERT(correctCountryCode.compare("0049") == 0);
}


void FormatNumberTest::TestGetAreaCodeFromGlobalNumberWithValidGlobalNumber()
{
	string correctAreaCode;
	correctAreaCode = Formatter->GetAreaCodeFromGlobalNumber("00492111234567");
	CPPUNIT_ASSERT(correctAreaCode.compare("0211") == 0);
	correctAreaCode = Formatter->GetAreaCodeFromGlobalNumber("004921311513029");
	CPPUNIT_ASSERT(correctAreaCode.compare("02131") == 0);
	correctAreaCode = Formatter->GetAreaCodeFromGlobalNumber("+4921311513029");
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
	correctNumber = Formatter->GetNumberFromGlobalNumber("+49307818820");
	CPPUNIT_ASSERT(correctNumber.compare("7818820") == 0);
}


void FormatNumberTest::TestGetCityNameFromGlobalNumber()
{
	string cityName;
	cityName = Formatter->GetCityNameFromGlobalNumber("00492111234567");
	CPPUNIT_ASSERT(cityName.compare("Düsseldorf") == 0);
	cityName = Formatter->GetCityNameFromGlobalNumber("004921311513029");
	CPPUNIT_ASSERT(cityName.compare("Kaarst") == 0);
	cityName = Formatter->GetCityNameFromGlobalNumber("004921591513029");
	CPPUNIT_ASSERT(cityName.compare("Meerbusch") == 0);
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
