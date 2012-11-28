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


	/**
	 * Cut first four digits of String and returns them
	 *
	 * @param String input e164 number
	 * @return String four digits long
	 */
	string GetCountryCodeFromGlobalNumber(string input);


	/**
	 * Created String is depending on the length of the given string
	 *
	 * @param String input e164 number
	 * @return String with length based on input
	 */
	string GetAreaCodeFromGlobalNumber(string input);


	/**
	 * Created String is based from the last seven digits of the given string
	 *
	 * @param String input e164 number
	 * @return String 7 digits long
	 */
	string GetNumberFromGlobalNumber(string input);


	/**
	 * Get areaCode, compare with onkz.txt and return city name based on areaCode
	 *
	 * @param String input e164 number
	 * @return String with city name based on areaCode
	 *
	 * @throw eOnkzFileStream
	 */
	string GetCityNameFromGlobalNumber(string input);


	/**
	 * Created PhoneNumber Object is filled with Strings
	 *
	 * @param String input e164 number
	 * @return PhoneNumber Object
	 */
	PhoneNumber* FormatGlobalNumberToLocalNumber(string input);

};

#endif

