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
	static bool IsInputNotEmpty(string input);
	static bool HasInputOnlyDigits(string input);
	// Input must be between 13 and 15 characters long
	static bool HasInputValidLength(string input);
	// call bool IsInputNotEmpty(string), bool HasInputOnlyDigit(string) and bool HasInputValidLength(string)
	// and return false when at least one of these methods fail
	static bool ValidateInputOnCorrectness(string input);
private:
	static string returnValue;
};


#endif /* VALIDATENUMBER_H_ */
