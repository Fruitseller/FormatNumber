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
	 * Check of input is between 13 and 16 characters long
	 *
	 * @param String input e164 number
	 * @return When input between 13 and 16 characters long --> TRUE
	 */
	static bool HasInputValidLength(string input);


	/**
	 * Called bool IsInputNotEmpty(string), bool HasInputOnlyDigit(string) and bool HasInputValidLength(string) and checked if all returned true.
	 *
	 * @param String input e164 number
	 * @return When ALL called methods return true --> TRUE
	 */
	static bool ValidateInputOnCorrectness(string input);
};


#endif /* VALIDATENUMBER_H_ */
