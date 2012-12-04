
#include "FormatNumberTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(FormatNumberTest);

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
	CPPUNIT_ASSERT(TestPhoneNumber->GetCityName().compare("Ahrensfelde") == 0);
	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("004921311513029");
	CPPUNIT_ASSERT(TestPhoneNumber->GetCityName().compare("Kaarst") == 0);

	/**
	 * TODO
	 * TDD Style
	 */
	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("00493999912345678");
	CPPUNIT_ASSERT(TestPhoneNumber->GetLocalNumber().compare("03999912345678") == 0);
	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("+493999912345678");
	CPPUNIT_ASSERT(TestPhoneNumber->GetLocalNumber().compare("03999912345678") == 0);
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

	/**
	 * TODO
	 * TDD Style
	 */
	correctNumber = Formatter->GetNumberFromGlobalNumber("+493999912345678");
	CPPUNIT_ASSERT(correctNumber.compare("12345678") == 0);
}


void FormatNumberTest::TestGetCityNameFromGlobalNumber()
{
	string cityName;
	cityName = Formatter->GetCityNameFromGlobalNumber("00492091234567");
	CPPUNIT_ASSERT(cityName.compare("Gelsenkirchen") == 0);
	cityName = Formatter->GetCityNameFromGlobalNumber("004921311513029");
	CPPUNIT_ASSERT(cityName.compare("Kaarst") == 0);
	cityName = Formatter->GetCityNameFromGlobalNumber("004921591513029");
	CPPUNIT_ASSERT(cityName.compare("Meerbusch") == 0);
}
