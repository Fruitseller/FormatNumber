#include <iostream>
#include <string>
#include <algorithm>

#include "FormatNumber.h"
#include "ValidateNumber.h"
#include "PhoneNumber.h"

using namespace std;

string returnValue = "";

string FormatNumber::ReplaceICCToNCC(string input)
{
	returnValue = input;

	returnValue.erase(0, 1);
	returnValue.insert(0, "00");
	return returnValue;
}


string FormatNumber::GetCountryCodeFromGlobalNumber(string input)
{
	string countryCode;
	returnValue = input;

	if (returnValue[0] == '+')
	{
		returnValue = ReplaceICCToNCC(returnValue);
	}

	for (int i = 0; i < 4; i++)
	{
		countryCode += returnValue[i];
	}

	return countryCode;
}


string FormatNumber::GetAreaCodeFromGlobalNumber(string input)
{
	string areaCode;
	unsigned int i = 4;
	returnValue = input;

	if (returnValue[0] == '+')
	{
		i = 3;
	}

	for (; i < (returnValue.length() - 7); i++)
	{
		areaCode += returnValue[i];
	}

	areaCode = "0" + areaCode;

	return areaCode;
}


string FormatNumber::GetNumberFromGlobalNumber(string input)
{
	string number;
	returnValue = input;

	for (unsigned int i = (returnValue.length() - 7); i < returnValue.length(); i++)
	{
		number += returnValue[i];
	}

	return number;
}


PhoneNumber* FormatNumber::FormatGlobalNumberToLocalNumber(string input)
{
	PhoneNumber* PhoneNumberObj = new PhoneNumber();
	returnValue = input;

	if (ValidateNumber::ValidateInputOnCorrectness(returnValue))
	{
		PhoneNumberObj->SetGlobalNumber(returnValue);

		PhoneNumberObj->SetCountryCode(GetCountryCodeFromGlobalNumber(returnValue));

		PhoneNumberObj->SetAreaCode(GetAreaCodeFromGlobalNumber(returnValue));

		PhoneNumberObj->SetNumber(GetNumberFromGlobalNumber(returnValue));

		PhoneNumberObj->SetLocalNumber(GetAreaCodeFromGlobalNumber(returnValue) + GetNumberFromGlobalNumber(returnValue));

		return PhoneNumberObj;
	}
	else
	{
		return NULL;
	}
}
