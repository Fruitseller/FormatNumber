#ifndef FORMATNUMBER_H
#define FORMATNUMBER_H


#include <string>
#include <iostream>
#include <fstream>
#include <map>

#include "ValidateNumber.h"
#include "OnkzFileStream.h"
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
	static string ReplaceICCToNCC(string input);

	// Returns four digit long string that is created from the given string
	string GetCountryCodeFromGlobalNumber(string input);

	// Returns variable string which is depending on the length of the given string
	string GetAreaCodeFromGlobalNumber(string input);

	// Returns seven digit long string that is created from the last seven digits of the given string
	string GetNumberFromGlobalNumber(string input);

	/**
	 * Get areaCode, compare with onkz.txt and return city name based on areaCode
	 *
	 * @param String input e164 number
	 * @return String with city name based on areaCode
	 */
	string GetCityNameFromGlobalNumber(string input);

	// Returns a PhoneNumber object created from the given international phonenumber string
	PhoneNumber* FormatGlobalNumberToLocalNumber(string input);

};

#endif

