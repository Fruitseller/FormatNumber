/*
 * ValidateNumber.cpp
 *
 *  Created on: 30.10.2012
 *      Author: bronkalla
 */

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
	if (input.length() < 13 || input.length() > 16)
	{
		return false;
	}
		return true;
}


bool ValidateNumber::ValidateInputOnCorrectness(string input)
{
	if (input[0] == '+')
	{
		input = FormatNumber::ReplaceICCToNCC(input);
	}

	if (IsInputNotEmpty(input) && HasInputOnlyDigits(input) && HasInputValidLength(input))
	{
		return true;
	}
	return false;
}
