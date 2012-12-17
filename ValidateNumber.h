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
	static bool IsInputNotEmpty(string input);

	/**
	 * Check if input has only digits
	 *
	 * @param String input e164 number
	 * @return When input has only digits --> TRUE
	 */
	static bool HasInputOnlyDigits(string input);


	/**
	 * Check if input is between 13 and 16 characters long
	 *
	 * @param String input e164 number
	 * @return When input between 13 and 16 characters long --> TRUE
	 */
	static bool HasInputValidLength(string input);


	/**
	 * Call bool IsInputNotEmpty(string), bool HasInputOnlyDigit(string) and bool HasInputValidLength(string) and checked if all returned true.
	 *
	 * @param String input e164 number
	 * @return When ALL called methods return true --> TRUE
	 */
	static bool ValidateInputOnCorrectness(string input);


	/**
	 * Check if parameter is '(' or ')' or '-' or ' '
	 *
	 * @param char input
	 * @return When input one of character --> TRUE
	 */
	static bool IsInputValidSymbol(char input);


	/**
	 * Search given string in prefix of map
	 *
	 * @param map<string, string> fileMap filled with CC or AC, string input
	 * @return When input in prefix of map --> TRUE
	 */
	static bool IsInputInMap(map<string, string> fileMap, string input);


	/**
	 * Check if char is digit
	 *
	 * @param char input
	 * @return When input = digit --> TRUE
	 */
	static bool IsInputDigit(char input);
};


#endif /* VALIDATENUMBER_H_ */
