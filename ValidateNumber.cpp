/*
 * ValidateNumber.cpp
 *
 *  Created on: 30.10.2012
 *      Author: bronkalla
 */

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


bool ValidateNumber::HasInputValidLength(PhoneNumber* GivenNumber)
{
	if ((GivenNumber->GetGlobalNumber().length() - 1) <= 15 && (GivenNumber->GetGlobalNumber().length() - 1) >= 8)
	{
		return true;
	}
	return false;
}


bool ValidateNumber::ValidateInputOnCorrectness(string input)
{
	if (input[0] == '+')
	{
		input = FormatNumber::ReplaceICCToNCC(input);
	}

	if (IsInputNotEmpty(input) && HasInputOnlyDigits(input) /*&& HasInputValidLength(input)*/)
	{
		return true;
	}
	return false;
}


bool ValidateNumber::IsInputValidSymbol(char input)
{
	return (input == '(' || input == ')' || input == '-' || input == ' ');
}


bool ValidateNumber::IsInputInMap(map<string, string> fileMap, string input)
{
	if (fileMap.find(input) != fileMap.end())
	{
		return true;
	}
	return false;
}


bool ValidateNumber::IsInputDigit(char input)
{
	return isdigit(input);
}
