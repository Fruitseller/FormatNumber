
#include "FormatNumberTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(FormatNumberTest);

void FormatNumberTest::setUp()
{
	TestPhoneNumber = new PhoneNumber();
	Formatter = new FormatNumber();
	TestPrefix = new PrefixContainer();
}


void FormatNumberTest::tearDown()
{
	delete TestPhoneNumber;
	delete Formatter;
	delete TestPrefix;
}


void FormatNumberTest::TestFormatGlobalNumberToLocalNumberWithValidNumber()
{
	/*
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

	//TODO
	//TDD Style
	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("00493999912345678");
	CPPUNIT_ASSERT(TestPhoneNumber->GetLocalNumber().compare("03999912345678") == 0);
	TestPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber("+493999912345678");
	CPPUNIT_ASSERT(TestPhoneNumber->GetLocalNumber().compare("03999912345678") == 0);
	*/
}


void FormatNumberTest::TestFormatGlobalNumberToLocalNumberWithUnvalidNumber()
{
	/*
	CPPUNIT_ASSERT(Formatter->FormatGlobalNumberToLocalNumber("00492134g3g11234567") == NULL);
	CPPUNIT_ASSERT(Formatter->FormatGlobalNumberToLocalNumber("0049(0211)1234567") == NULL);
	CPPUNIT_ASSERT(Formatter->FormatGlobalNumberToLocalNumber("+49 (0211) 1234567") == NULL);
	*/
}


void FormatNumberTest::TestGetCountryCodeFromGlobalNumberWithValidGlobalNumber()
{
	/*
	string correctCountryCode;
	correctCountryCode = Formatter->GetCountryCodeFromGlobalNumber("00492111234567");
	CPPUNIT_ASSERT(correctCountryCode.compare("0049") == 0);
	correctCountryCode = Formatter->GetCountryCodeFromGlobalNumber("004921311513029");
	CPPUNIT_ASSERT(correctCountryCode.compare("0049") == 0);
	correctCountryCode = Formatter->GetCountryCodeFromGlobalNumber("+4921311513029");
	CPPUNIT_ASSERT(correctCountryCode.compare("0049") == 0);
	*/
}


void FormatNumberTest::TestGetAreaCodeFromGlobalNumberWithValidGlobalNumber()
{
	/*
	string correctAreaCode;
	correctAreaCode = Formatter->GetAreaCodeFromGlobalNumber("00492111234567");
	CPPUNIT_ASSERT(correctAreaCode.compare("211") == 0);
	correctAreaCode = Formatter->GetAreaCodeFromGlobalNumber("004921311513029");
	CPPUNIT_ASSERT(correctAreaCode.compare("2131") == 0);
	correctAreaCode = Formatter->GetAreaCodeFromGlobalNumber("+4921311513029");
	CPPUNIT_ASSERT(correctAreaCode.compare("2131") == 0);
	correctAreaCode = Formatter->GetAreaCodeFromGlobalNumber("0049307818820");
	CPPUNIT_ASSERT(correctAreaCode.compare("30") == 0);
	*/
}


void FormatNumberTest::TestGetNumberFromGlobalNumberWithValidGlobalNumber()
{
	/*
	string correctNumber;
	correctNumber = Formatter->GetNumberFromGlobalNumber("00492111234567");
	CPPUNIT_ASSERT(correctNumber.compare("1234567") == 0);
	correctNumber = Formatter->GetNumberFromGlobalNumber("004921311513029");
	CPPUNIT_ASSERT(correctNumber.compare("1513029") == 0);
	correctNumber = Formatter->GetNumberFromGlobalNumber("0049307818820");
	CPPUNIT_ASSERT(correctNumber.compare("7818820") == 0);
	correctNumber = Formatter->GetNumberFromGlobalNumber("+49307818820");
	CPPUNIT_ASSERT(correctNumber.compare("7818820") == 0);

	//TODO
	//TDD Style
	correctNumber = Formatter->GetNumberFromGlobalNumber("+493999912345678");
	CPPUNIT_ASSERT(correctNumber.compare("12345678") == 0);
	*/
}


void FormatNumberTest::TestGetCityNameFromGlobalNumber()
{
	/*
	string cityName;
	cityName = Formatter->GetCityNameFromGlobalNumber("00492091234567");
	CPPUNIT_ASSERT(cityName.compare("Gelsenkirchen") == 0);
	cityName = Formatter->GetCityNameFromGlobalNumber("004921311513029");
	CPPUNIT_ASSERT(cityName.compare("Kaarst") == 0);
	cityName = Formatter->GetCityNameFromGlobalNumber("004921591513029");
	CPPUNIT_ASSERT(cityName.compare("Meerbusch") == 0);
	*/
}


void FormatNumberTest::TestNormalizePhoneNumber()
{
	string normalizedNumber;
	normalizedNumber = Formatter->NormalizePhoneNumber("+492116666666");
	CPPUNIT_ASSERT(normalizedNumber.compare("492116666666") == 0);
	normalizedNumber = Formatter->NormalizePhoneNumber("00492116666666");
	CPPUNIT_ASSERT(normalizedNumber.compare("492116666666") == 0);
	normalizedNumber = Formatter->NormalizePhoneNumber("492116666666");
	CPPUNIT_ASSERT(normalizedNumber.compare("492116666666") == 0);

}


void FormatNumberTest::TestExtractPrefixFromMapWithValidInput()
{
	map<string, string> fileMap;

	fileMap = FileStreamConverter::LoadCCMap();
	TestPrefix = Formatter->ExtractPrefixFromMap(fileMap, "492116666666");
	CPPUNIT_ASSERT(TestPrefix->GetPrefix().compare("49") == 0);
	CPPUNIT_ASSERT(TestPrefix->GetRemainder().compare("2116666666") == 0);

	fileMap = FileStreamConverter::LoadACMapFromCC("49");
	TestPrefix = Formatter->ExtractPrefixFromMap(fileMap, "2116666666");
	CPPUNIT_ASSERT(TestPrefix->GetPrefix().compare("211") == 0);
	CPPUNIT_ASSERT(TestPrefix->GetRemainder().compare("6666666") == 0);
}


void FormatNumberTest::TestExtractPrefixFromMapWithFalseInput()
{
	map<string, string> fileMap;

	fileMap = FileStreamConverter::LoadCCMap();
	CPPUNIT_ASSERT_THROW(Formatter->ExtractPrefixFromMap(fileMap, "0042211666666"), eFormatNumber);
	CPPUNIT_ASSERT_THROW(Formatter->ExtractPrefixFromMap(fileMap, "0049deineMudda"), eFormatNumber);
}


void FormatNumberTest::TestParsePhoneNumberWithValidInput()
{
	TestPhoneNumber = Formatter->ParsePhoneNumber("0049211666666");
	CPPUNIT_ASSERT(TestPhoneNumber->GetCountryCode().compare("49") == 0);
	CPPUNIT_ASSERT(TestPhoneNumber->GetAreaCode().compare("211") == 0);
	CPPUNIT_ASSERT(TestPhoneNumber->GetNumber().compare("666666") == 0);

	TestPhoneNumber = Formatter->ParsePhoneNumber("004921317777777");
	CPPUNIT_ASSERT(TestPhoneNumber->GetCountryCode().compare("49") == 0);
	CPPUNIT_ASSERT(TestPhoneNumber->GetAreaCode().compare("2131") == 0);
	CPPUNIT_ASSERT(TestPhoneNumber->GetNumber().compare("7777777") == 0);

	TestPhoneNumber = Formatter->ParsePhoneNumber("004921188888888");
	CPPUNIT_ASSERT(TestPhoneNumber->GetCountryCode().compare("49") == 0);
	CPPUNIT_ASSERT(TestPhoneNumber->GetAreaCode().compare("211") == 0);
	CPPUNIT_ASSERT(TestPhoneNumber->GetNumber().compare("88888888") == 0);
}


void FormatNumberTest::TestParsePhoneNumberWithFalseInput()
{
	CPPUNIT_ASSERT_THROW(TestPhoneNumber = Formatter->ParsePhoneNumber("0042211666666"), eFormatNumber);
}


void FormatNumberTest::TestEraseNotDigitFromPhoneNumber()
{
	string cleanNumber;
	cleanNumber = Formatter->EraseNotDigitFromPhoneNumber("a6abcdefghijklmnopqrstuvwxyz6a6a6a6a6a");
	cleanNumber = Formatter->EraseNotDigitFromPhoneNumber("a6abcdefgh6a6a6a6a6a");
	CPPUNIT_ASSERT(cleanNumber.compare("666666") == 0);
}


