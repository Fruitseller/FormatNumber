#ifndef FORMATNUMBER_H
#define FORMATNUMBER_H

#define ICC InternationalCountryCode
#define NCC NationalCountryCode

#include <string>
#include "PhoneNumber.h"

using namespace std;

class FormatNumber
{
public:
	// Replace "+XX" to "00XX" so other methods work normally
	string ReplaceICCToNCC(string input);

	// Returns four digit long string that is created from the given string
	string GetCountryCodeFromGlobalNumber(string input);
	// Returns variable string which is depending on the length of the given string
	string GetAreaCodeFromGlobalNumber(string input);
	// Returns seven digit long string that is created from the last seven digits of the given string
	string GetNumberFromGlobalNumber(string input);
	// Returns a national phonenumber string created from the given international phonenumber string
	PhoneNumber* FormatGlobalNumberToLocalNumber(string input);

private:
	// Is needed because of ReplaceICCToNCC
	string returnValue;
};

#endif

