

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

	cityName = OnkzFileStream::FindCityNameFromMap(OnkzFileStream::GetMapFromFileDirectory("/home/bronkalla/workspace/FormatNumber/src/onkz.txt")
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
		//cout << "ich gehe jetzt den string: " << number[i] << " zeichen für zeichen durch " << i << endl;
		if (ValidateNumber::IsInputValidSymbol(number[i]))
		{
			//cout << "Habe ein gültiges Sonderzeichen gefunden!!!" << endl;
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
			//cout << "tmp: " << tmp << endl;
			if (ValidateNumber::IsInputInMap(fileMap, tmp))
			{
				//cout << "bin drin" << endl;
				PrefixString->SetPrefix(tmp);
				pos = tmp.size();
				PrefixString->SetRemainder(EraseNotDigitFromPhoneNumber(number.substr(pos)));
				//cout << "Prefix: " << PrefixString->GetPrefix() << endl;
				//cout << "Remainder: " << PrefixString->GetRemainder() << endl;
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
	PhoneNumber* Number = new PhoneNumber();
	Number->SetGlobalNumber(input);

	string normalizedNumber = NormalizePhoneNumber(input);

	map<string, string> CCMap = OnkzFileStream::LoadCCMap();

	PrefixContainer* CCString = new PrefixContainer();
	CCString = ExtractPrefixFromMap(CCMap, normalizedNumber);

	map<string, string> ACMap = OnkzFileStream::LoadACMapFromCC(CCString->GetPrefix());
	PrefixContainer* ACString = new PrefixContainer();
	ACString = ExtractPrefixFromMap(ACMap, CCString->GetRemainder());


	Number->SetCountryCode(CCString->GetPrefix());
	Number->SetAreaCode(ACString->GetPrefix());
	Number->SetCityName(OnkzFileStream::FindCityNameFromMap(ACMap, Number->GetAreaCode()));
	Number->SetCityName(ACMap[ACString->GetPrefix()]);
	Number->SetNumber(ACString->GetRemainder());
	Number->SetGlobalNumber("+" + Number->GetCountryCode() + Number->GetAreaCode() + Number->GetNumber());
	Number->SetLocalNumber("0" + Number->GetAreaCode() + Number->GetNumber());

	return Number;
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
