
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


