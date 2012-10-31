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
	void SetAreaCode(string areaCode);

	string GetCountryCode();
	void SetCountryCode(string countryCode);

	string GetGlobalNumber();
	void SetGlobalNumber(string globalNumber);

	string GetLocalNumber();
	void SetLocalNumber(string localNumber);

	string GetNumber();
	void SetNumber(string number);

private:
	string globalNumber;
	string localNumber;
	string countryCode;
	string areaCode;
	string number;
};


#endif /* PHONENUMBER_H_ */
