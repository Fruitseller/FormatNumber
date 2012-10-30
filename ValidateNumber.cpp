/*
 * ValidateNumber.cpp
 *
 *  Created on: 30.10.2012
 *      Author: bronkalla
 */

#include <iostream>
#include <string>

#include "FormatNumber.h"
#include "ValidateNumber.h"

using namespace std;

string ValidateNumber::returnValue = "";


bool ValidateNumber::IsInputNotEmpty(string input)
{
	returnValue = input;

	return !(returnValue.empty());
}


bool ValidateNumber::HasInputOnlyDigits(string input)
{
	returnValue = input;

	for (unsigned int i = 0; i < returnValue.length(); ++i)
	{
		if (!isdigit(returnValue[i]))
			return false;
	}
	return true;
}


bool ValidateNumber::HasInputValidLength(string input)
{
	returnValue = input;

	if (returnValue.length() < 13 || returnValue.length() > 15)
	{
		return false;
	}
		return true;
}


bool ValidateNumber::ValidateInputOnCorrectness(string input)
{
	returnValue = input;

	if (returnValue[0] == '+')
	{
		FormatNumber* formatter = new FormatNumber();
		returnValue = formatter->ReplaceICCToNCC(returnValue);
		delete formatter;
	}

	if (IsInputNotEmpty(returnValue) && HasInputOnlyDigits(returnValue) && HasInputValidLength(returnValue))
	{
		return true;
	}
	return false;
}
