#include <iostream>
#include <string>
#include <algorithm>

#include "FormatNumber.h"

using namespace std;

bool FormatNumber::IsInputNotEmptyAndDigit(string const &input)
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

	if (IsInputNotEmptyAndDigit(input))
	{

		countryCode = GetCountryCodeFromGlobalNumber(input);
		cout << endl << countryCode << endl;

		areaCode = GetAreaCodeFromGlobalNumber(input);
		cout << areaCode << endl;

		number = GetNumberFromGlobalNumber(input);
		cout << number << endl;
		cout << endl;

		localFormat = areaCode + number;


		return localFormat;
	}
	else
	{
		return "Error: invalid input!!\n";
	}
}

