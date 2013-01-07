

#include "FormatNumber.h"


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

	cityName = FileStreamConverter::FindCityNameFromMap(FileStreamConverter::GetMapFromFileDirectory("/home/bronkalla/workspace/FormatNumber/src/areacode49.txt")
													, GetAreaCodeFromGlobalNumber(input));

	return cityName;
}


PhoneNumber* FormatNumber::FormatGlobalNumberToLocalNumber(string input)
{

	if (ValidateNumber::ValidateInputOnCorrectness(input))
	{
		PhoneNumber* PhoneNumberObj = new PhoneNumber();

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


string FormatNumber::NormalizePhoneNumber(string input)
{
	if (input[0] == '+')
	{
		input.erase(0, 1);
	}

	if (input[0] == '0' || input[1] == '0')
	{
		input.erase(0, 2);
	}
	return input;
}


PrefixContainer* FormatNumber::ExtractPrefixFromMap(map<string, string> fileMap, string number)
{
	PrefixContainer* PrefixString = new PrefixContainer();
	string tmp;
	size_t pos;

	for (unsigned int i = 0; i < number.length(); i++)
	{
		if (ValidateNumber::IsInputValidSymbol(number[i]))
		{
			i++;
			continue;
		}
		else if (!ValidateNumber::IsInputDigit(number[i]))
		{
			throw eFormatNumber();
		}
		else
		{
			tmp += number[i];
			if (ValidateNumber::IsInputInMap(fileMap, tmp))
			{
				PrefixString->SetPrefix(tmp);
				pos = tmp.size();
				PrefixString->SetRemainder(EraseNotDigitFromPhoneNumber(number.substr(pos)));
				break;
			}
			else
			{
				if (i == (number.length() - 1))
				{
					throw eFormatNumber();
				}
			}
		}
	}
	return PrefixString;
}


PhoneNumber* FormatNumber::ParsePhoneNumber(string input)
{
	PhoneNumber* MyPhoneNumber = new PhoneNumber();

	string normalizedNumber = NormalizePhoneNumber(input);

	map<string, string> CCMap = FileStreamConverter::LoadCCMap();

	PrefixContainer* CCString = new PrefixContainer();
	CCString = ExtractPrefixFromMap(CCMap, normalizedNumber);

	map<string, string> ACMap = FileStreamConverter::LoadACMapFromCC(CCString->GetPrefix());
	PrefixContainer* ACString = new PrefixContainer();
	ACString = ExtractPrefixFromMap(ACMap, CCString->GetRemainder());


	MyPhoneNumber->SetCountryCode(CCString->GetPrefix());
	MyPhoneNumber->SetAreaCode(ACString->GetPrefix());
	MyPhoneNumber->SetCityName(FileStreamConverter::FindCityNameFromMap(ACMap, MyPhoneNumber->GetAreaCode()));
	MyPhoneNumber->SetCityName(ACMap[ACString->GetPrefix()]);
	MyPhoneNumber->SetNumber(ACString->GetRemainder());
	MyPhoneNumber->SetGlobalNumber("+" + MyPhoneNumber->GetCountryCode() + MyPhoneNumber->GetAreaCode() + MyPhoneNumber->GetNumber());
	MyPhoneNumber->SetLocalNumber("0" + MyPhoneNumber->GetAreaCode() + MyPhoneNumber->GetNumber());

	return MyPhoneNumber;
}


string FormatNumber::EraseNotDigitFromPhoneNumber(string input)
{
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			input.erase(i, 1);
			i--;
		}
	}
	return input;
}
