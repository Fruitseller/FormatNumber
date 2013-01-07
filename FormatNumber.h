#ifndef FORMATNUMBER_H
#define FORMATNUMBER_H


#include <string>
#include <iostream>
#include <fstream>
#include <map>

#include "ValidateNumber.h"
#include "FileStreamConverter.h"
#include "PhoneNumber.h"
#include "PrefixContainer.h"
#include "eFormatNumber.h"

using namespace std;

class FormatNumber
{
public:
	/**
	 * DEPRECATED
	 * Replacing ICC to NCC in given phonenumber string.
	 *
	 * @param	String input e164 number
	 * @return	String Creates ICC short format, +XX >> 00XX
	 *
	 * @throw
	 */
	static string ReplaceICCToNCC(string input);


	/**
	 * DEPRECATED
	 * Cut first four digits of String and returns them
	 *
	 * @param String input e164 number
	 * @return String four digits long
	 */
	string GetCountryCodeFromGlobalNumber(string input);


	/**
	 * DEPRECATED
	 * Created String is depending on the length of the given string
	 *
	 * @param String input e164 number
	 * @return String with length based on input
	 */
	string GetAreaCodeFromGlobalNumber(string input);


	/**
	 * DEPRECATED
	 * Created String is based on the last seven digits of the given string
	 *
	 * @param String input e164 number
	 * @return String 7 digits long
	 */
	string GetNumberFromGlobalNumber(string input);


	/**
	 * DEPRECATED
	 * Get areaCode, compare with onkz.txt and return city name based on areaCode
	 *
	 * @param String input e164 number
	 * @return String with city name based on areaCode
	 *
	 * @throw eOnkzFileStream
	 */
	string GetCityNameFromGlobalNumber(string input);


	/**
	 * DEPRECATED
	 * Created PhoneNumber Object is filled with Strings
	 *
	 * @param String input e164 number
	 * @return PhoneNumber Object
	 */
	PhoneNumber* FormatGlobalNumberToLocalNumber(string input);

	/**
	 * Delete "+" or "00" when at first position
	 *
	 * @param String input e164 number
	 * @return normalized number without "+" or "00"
	 */
	string NormalizePhoneNumber(string input);

	/**
	 * Searched prefix in map is based on given string
	 *
	 * @param map<string, string> fileMap filled with CC or AC, string number
	 * @return PrefixContainer* with prefix=founded number and remainder=leftover
	 */
	PrefixContainer* ExtractPrefixFromMap(map<string, string> fileMap, string number);


	/**
	 * Find CC and AC in created map, fill out PhoneNumber Obj and return this Obj
	 *
	 * @param String input e164 number
	 * @return PhoneNumber* Obj filled with all informations
	 */
	PhoneNumber* ParsePhoneNumber(string input);


	/**
	 * Go through given string and erase all not digits
	 *
	 * @param String input string with digits mixed with no digits
	 * @return string with only digits
	 */
	string EraseNotDigitFromPhoneNumber(string input);

};

#endif

