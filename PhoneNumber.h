/*
 * PhoneNumber.h
 *
 *  Created on: 31.10.2012
 *      Author: bronkalla
 */

#ifndef PHONENUMBER_H_
#define PHONENUMBER_H_

#include <iostream>
#include <string>

using namespace std;

class PhoneNumber
{
public:
	string GetAreaCode();
	void SetAreaCode(string);

	string GetCountryCode();
	void SetCountryCode(string);

	string GetGlobalNumber();
	void SetGlobalNumber(string);

	string GetLocalNumber();
	void SetLocalNumber(string);

	string GetNumber();
	void SetNumber(string);

	string GetCityName();
	void SetCityName(string);

private:
	string globalNumber;
	string localNumber;
	string countryCode;
	string areaCode;
	string cityName;
	string number;
};


#endif /* PHONENUMBER_H_ */
