/*
 * ValidateNumber.h
 *
 *  Created on: 29.10.2012
 *      Author: bronkalla
 */


#ifndef VALIDATENUMBER_H_
#define VALIDATENUMBER_H_

#include <iostream>
#include <string>

#include "FormatNumber.h"
#include "PhoneNumber.h"
#include "eFalseNumberLength.h"

using namespace std;

class ValidateNumber
{
public:
	/**
	 * Check if input is not empty
	 *
	 * @param String input e164 number
	 * @return When input NOT empty --> TRUE
	 */
	static bool IsInputNotEmpty(string);

	/**
	 * Check if input has only digits
	 *
	 * @param String input e164 number
	 * @return When input has only digits --> TRUE
	 */
	static bool HasInputOnlyDigits(string);


	/**
	 * Check if input is between 8 and 15 characters long
	 *
	 * @throw eFalseNumberLength
	 * @param String input e164 number
	 * @return When input between 8 and 15 characters long --> TRUE
	 */
	static bool HasInputValidLength(PhoneNumber*);


	/**
	 * Check if parameter is '(' or ')' or '-' or ' '
	 *
	 * @param char input
	 * @return When input one of character --> TRUE
	 */
	static bool IsInputValidSymbol(char);


	/**
	 * Search given string in prefix of map
	 *
	 * @param map<string, string> fileMap filled with CC or AC, string input
	 * @return When input in prefix of map --> TRUE
	 */
	static bool IsInputInMap(map<string, string>, string);


	/**
	 * Check if char is digit
	 *
	 * @param char input
	 * @return When input = digit --> TRUE
	 */
	static bool IsInputDigit(char);
};


#endif /* VALIDATENUMBER_H_ */
