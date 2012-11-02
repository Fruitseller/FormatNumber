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

bool ValidateNumber::IsInputNotEmpty(string input)
{
	return !(input.empty());
}


bool ValidateNumber::HasInputOnlyDigits(string input)
{
	for (unsigned int i = 0; i < input.length(); ++i)
	{
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}


bool ValidateNumber::HasInputValidLength(string input)
{
	if (input.length() < 13 || input.length() > 15)
	{
		return false;
	}
		return true;
}


bool ValidateNumber::ValidateInputOnCorrectness(string input)
{
	if (input[0] == '+')
	{
		FormatNumber* formatter = new FormatNumber();
		input = formatter->ReplaceICCToNCC(input);
		delete formatter;
	}

	if (IsInputNotEmpty(input) && HasInputOnlyDigits(input) && HasInputValidLength(input))
	{
		return true;
	}
	return false;
}
