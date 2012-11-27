

#include "FormatNumber.h"


//using namespace std;

string FormatNumber::ReplaceICCToNCC(string input)
{

	input.erase(0, 1);
	input.insert(0, "00");
	return input;
}


string FormatNumber::GetCountryCodeFromGlobalNumber(string input)
{
	string countryCode;

	if (input[0] == '+')
	{
		input = FormatNumber::ReplaceICCToNCC(input);
	}

	for (int i = 0; i < 4; i++)
	{
		countryCode += input[i];
	}

	return countryCode;
}


string FormatNumber::GetAreaCodeFromGlobalNumber(string input)
{
	string areaCode;
	unsigned int i(4);

	if (input[0] == '+')
	{
		i = 3;
	}

	for (; i < (input.length() - 7); i++)
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


string FormatNumber::GetCityNameFromGlobalNumber(string input)
{
	map<string, string> onkzMapList;
	string cityName;


	try
	{
		onkzMapList = OnkzFileStream::GetMapFromFileDirectory("/home/bronkalla/workspace/FormatNumber/src/onkz.txt");
	}
	catch (const eOnkzFileStream& Exception)
	{
		cerr << "Datei konnte nicht gelesen werden" << endl;
		terminate();
	}

	input = GetAreaCodeFromGlobalNumber(input);

	cityName = OnkzFileStream::FindCityNameFromMap(onkzMapList, input);

	return cityName;
}


PhoneNumber* FormatNumber::FormatGlobalNumberToLocalNumber(string input)
{
	PhoneNumber* PhoneNumberObj = new PhoneNumber();

	if (ValidateNumber::ValidateInputOnCorrectness(input))
	{
		PhoneNumberObj->SetGlobalNumber(input);
		PhoneNumberObj->SetCountryCode(GetCountryCodeFromGlobalNumber(input));
		PhoneNumberObj->SetAreaCode(GetAreaCodeFromGlobalNumber(input));
		PhoneNumberObj->SetNumber(GetNumberFromGlobalNumber(input));
		PhoneNumberObj->SetLocalNumber(GetAreaCodeFromGlobalNumber(input) + GetNumberFromGlobalNumber(input));
		PhoneNumberObj->SetCityName(GetCityNameFromGlobalNumber(input));


		return PhoneNumberObj;
	}
	else
	{
		return NULL;
	}
}
