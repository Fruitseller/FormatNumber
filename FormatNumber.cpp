#include <iostream>
#include <string>
#include <algorithm>

#include "FormatNumber.h"

using namespace std;

	string globalFormat;

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
	} else
	{
		return false;
	}
}

string FormatNumber::FormatGlobalNumberToLocalNumber(string input)
{

	string number;
	string countryCode;
	string areaCode;
	string localFormat;

	if (IsInputNotEmptyAndDigit(input))
	{
		for (int i = 0; i < 4; i++)
		{
			countryCode += input[i];
		}

		cout << "\nCountrycode: " << countryCode << endl;

		for (int i = 4; i < (input.length() - 7); i++)
		{
			areaCode += input[i];
		}

		cout << "Areacode: " << areaCode << endl;

		for (unsigned int i = (input.length() - 7); i <= input.length(); i++)
		{
			number += input[i];
		}

		cout << "Nummer: " << number << endl;
		cout << endl;

		localFormat = "0" + areaCode + number;


		return localFormat;
	}
	else
	{
		return "Error: invalid input!!\n";
	}
}
