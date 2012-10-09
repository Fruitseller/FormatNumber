#include <iostream>
#include <string>
#include <algorithm>

#include "FormatNumber.h"

using namespace std;

/*
public:
	const string& getAreaCode() const;
	void setAreaCode(const string& areaCode);
	const string& getCountryCode() const;
	void setCountryCode(const string& countryCode);
	const string& getGlobalFormat() const;
	void setGlobalFormat(const string& globalFormat);
	const string& getLocalFormat() const;
	void setLocalFormat(const string& localFormat);
	const string& getNumber() const;
	void setNumber(const string& number);

private:
*/

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


	/*
	const string& FormatNumber::getAreaCode() const
	{
		return areaCode;
	}

	void FormatNumber::setAreaCode(const string& areaCode) {
		this->areaCode = areaCode;
	}

	const string& FormatNumber::getCountryCode() const {
		return countryCode;
	}

	void FormatNumber::setCountryCode(const string& countryCode) {
		this->countryCode = countryCode;
	}

	const string& FormatNumber::getGlobalFormat() const {
		return globalFormat;
	}

	void FormatNumber::setGlobalFormat(const string& globalFormat) {
		this->globalFormat = globalFormat;
	}

	const string& FormatNumber::getLocalFormat() const {
		return localFormat;
	}

	void FormatNumber::setLocalFormat(const string& localFormat) {
		this->localFormat = localFormat;
	}

	const string& FormatNumber::getNumber() const {
		return number;
	}

	void FormatNumber::setNumber(const string& number) {
		this->number = number;
	}
	*/

