#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

#include <map>
#include <vector>

#include <string.h>

#include "FormatNumber.h"
#include "ValidateNumber.h"
#include "OnkzFileStream.h"
#include "PhoneNumber.h"

using namespace std;

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
		input = ReplaceICCToNCC(input);
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
	unsigned int i = 4;

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
	/*
	string cityName;
	string lineTmpString;
	size_t pos;
	string tmp;
	vector<string> tmpVectorOfLines;
	unsigned int lineCounter(0);
	map<string, string> onkzMapList;

	ifstream fileStream("/home/bronkalla/workspace/FormatNumber/src/onkz.txt");

	if (!fileStream)
	{
		cerr << "LOL alles kaputt";
	}


	while (getline(fileStream, lineTmpString))
	{
		if (lineTmpString.at(0) != '#')
			tmpVectorOfLines.push_back(lineTmpString);
	}
	fileStream.close();
	cout << "vector[0]: " << tmpVectorOfLines[0] << endl;
	cout << "vector.back(): " << tmpVectorOfLines.back() << endl;
	cout << "vector[5204]: " << tmpVectorOfLines[5204] << endl;
	cout << "size: " << tmpVectorOfLines.size() << endl;


	for (; lineCounter < tmpVectorOfLines.size(); lineCounter++)
	{

		for (unsigned int i = 0; i < tmpVectorOfLines[lineCounter].length(); i++)
		{
			if (tmpVectorOfLines[lineCounter].at(i) == ';')
			{

				tmp = "0" + tmp;
				onkzMapList[tmp];
				pos = tmpVectorOfLines[lineCounter].find(';');

				onkzMapList[tmp] = tmpVectorOfLines[lineCounter].substr(pos + 1);

				i = tmpVectorOfLines[lineCounter].length();

				cout << "Map[" << tmp << "]: " << onkzMapList[tmp] << endl;
				tmp = "";
			}
			else
			{
				tmp += tmpVectorOfLines[lineCounter].at(i);
			}
		}
	}
	input = GetAreaCodeFromGlobalNumber(input);
	cityName = onkzMapList.find(input)->second;
	cout << "02131: " << onkzMapList.find("02131")->second << endl;

	*/
	map<string, string> onkzMapList;
	string cityName;

	OnkzFileStream* onkzFileStream = new OnkzFileStream();

	onkzMapList = onkzFileStream->CreateMapWithOnkz();
	input = GetAreaCodeFromGlobalNumber(input);

	cityName = onkzFileStream->FindCityNameFromMap(onkzMapList, input);

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
