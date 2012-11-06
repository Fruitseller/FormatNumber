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
	/**
	 * Replacing ICC to NCC in given phonenumber string.
	 *
	 * @param	String input e164 number
	 * @return	String Creates ICC short format, +XX >> 00XX
	 *
	 * @throw
	 */
	string ReplaceICCToNCC(string input);

	// Returns four digit long string that is created from the given string
	string GetCountryCodeFromGlobalNumber(string input);

	// Returns variable string which is depending on the length of the given string
	string GetAreaCodeFromGlobalNumber(string input);

	// Returns seven digit long string that is created from the last seven digits of the given string
	string GetNumberFromGlobalNumber(string input);

	// Returns a PhoneNumber object created from the given international phonenumber string
	PhoneNumber* FormatGlobalNumberToLocalNumber(string input);

};

#endif

