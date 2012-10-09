#ifndef FORMATNUMBER_H
#define FORMATNUMBER_H

#include <string>

using namespace std;

class FormatNumber
{
public:
	bool IsInputNotEmptyAndDigit(string const &input);
	string FormatGlobalNumberToLocalNumber(string input);

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
		*/

};

#endif


