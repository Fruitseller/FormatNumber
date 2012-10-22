#include <iostream>
#include <string>
#include <algorithm>

#include "FormatNumber.h"

using namespace std;

//############################################################
// TODO
// Delete the debug cout!!!
//############################################################

bool FormatNumber::IsInputNotEmpty(string input)
{
	if (input.empty())
	{
		return false;
	}
	else
	{
		cout << "Input is not empty\n";
		return true;
	}
}

bool FormatNumber::HasInputOnlyDigit(string input)
{
	for (unsigned int i = 0; i < input.length(); ++i)
	{
		if (!isdigit(input[i]))
			return false;
	}
	cout << "Input has only digit\n";
	return true;
}

bool FormatNumber::HasInputValidLength(string input)
{
	if (input.length() < 13 or input.length() > 15)
	{
		cout << "Something is wrong with the length\n";
		return false;
	}
	else
	{
		cout << "Input has valid length\n";
		return true;
	}
}

bool FormatNumber::ValidateInputOnCorrectness(string input)
{
	if (IsInputNotEmpty(input) and HasInputOnlyDigit(input) and HasInputValidLength(input))
	{
		cout << "Validate OK";
		return true;
	}
	else
	{
		cout << "NOT OK";
		return false;
	}
}

bool FormatNumber::IsInputNotEmptyAndDigit(string input)
{
	if (!(input.empty()))
	{
		for (unsigned int i = 0; i < input.length(); ++i)
		{
			if (!isdigit(input[i]))
				return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

string FormatNumber::GetCountryCodeFromGlobalNumber(string input)
{
	string countryCode;

	for (int i = 0; i < 4; i++)
	{
		countryCode += input[i];
	}

	return countryCode;
}

string FormatNumber::GetAreaCodeFromGlobalNumber(string input)
{
	string areaCode;

	for (unsigned int i = 4; i < (input.length() - 7); i++)
	{
		areaCode += input[i];
	}

	areaCode = "0" + areaCode;

	return areaCode;
}

string FormatNumber::GetNumberFromGlobalNumber(string input)
{
	string number;

	for (unsigned int i = (input.length() - 7); i < input.length(); i++)
	{
		number += input[i];
	}

	return number;
}

string FormatNumber::FormatGlobalNumberToLocalNumber(string input)
{

	string number;
	string countryCode;
	string areaCode;
	string localFormat;

	//if (IsInputNotEmptyAndDigit(input))
	if (ValidateInputOnCorrectness(input))
	{

		countryCode = GetCountryCodeFromGlobalNumber(input);
		cout << endl << "Ländercode:  " << countryCode << endl;

		areaCode = GetAreaCodeFromGlobalNumber(input);
		cout << "Ortsvorwahl: " << areaCode << endl;

		number = GetNumberFromGlobalNumber(input);
		cout << "Rufnummer:   " << number << endl;
		cout << endl;

		localFormat = areaCode + number;


		return localFormat;
	}
	else
	{
		return "Error: invalid input!!\n";
	}
}
