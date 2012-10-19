#ifndef FORMATNUMBER_H
#define FORMATNUMBER_H

#include <string>

using namespace std;

class FormatNumber
{
public:
	// Returns true if the given string input is NOT empty and filled with only digits
	bool IsInputNotEmptyAndDigit(string const &input);
	// Returns four digit long string that is created from the given string
	string GetCountryCodeFromGlobalNumber(string input);
	// Returns variable string which is depending on the length of the given string
	string GetAreaCodeFromGlobalNumber(string input);
	// Returns seven digit long string that is created from the last seven digits of the given string
	string GetNumberFromGlobalNumber(string input);
	// Returns a national phonenumber string created from the given international phonenumber string
	string FormatGlobalNumberToLocalNumber(string input);
};

#endif


