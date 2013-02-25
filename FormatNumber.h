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
	 * Delete "+" or "00" when at first position
	 *
	 * @param String input e164 number
	 * @return normalized number without "+" or "00"
	 */
	string NormalizePhoneNumber(string);

	/**
	 * Searched prefix in map is based on given string
	 *
	 * @param map<string, string> fileMap filled with CC or AC, string number
	 * @return PrefixContainer* with prefix=founded number and remainder=leftover
	 */
	PrefixContainer* ExtractPrefixFromMap(map<string, string>, string);


	/**
	 * Find CC and AC in created map, fill out PhoneNumber Obj and return this Obj
	 *
	 * @param String input e164 number
	 * @return PhoneNumber* Obj filled with all informations
	 */
	PhoneNumber* ParsePhoneNumber(string);


	/**
	 * Go through given string and erase all not digits
	 *
	 * @param String input string with digits mixed with no digits
	 * @return string with only digits
	 */
	string EraseNotDigitFromPhoneNumber(string);

};

#endif

