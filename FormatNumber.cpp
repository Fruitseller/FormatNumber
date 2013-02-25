
#include "FormatNumber.h"

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
					throw eFormatNumber(tmp);
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
