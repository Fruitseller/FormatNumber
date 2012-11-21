/*
 * PhoneNumber.cpp
 *
 *  Created on: 31.10.2012
 *      Author: bronkalla
 */

#include "PhoneNumber.h"

using namespace std;

string PhoneNumber::GetAreaCode()
{
	return areaCode;
}

void PhoneNumber::SetAreaCode(string areaCode)
{
	this->areaCode = areaCode;
}


string PhoneNumber::GetCountryCode()
{
	return countryCode;
}

void PhoneNumber::SetCountryCode(string countryCode)
{
	this->countryCode = countryCode;
}


string PhoneNumber::GetGlobalNumber()
{
	return globalNumber;
}

void PhoneNumber::SetGlobalNumber(string globalNumber)
{
	this->globalNumber = globalNumber;
}


string PhoneNumber::GetLocalNumber()
{
	return localNumber;
}

void PhoneNumber::SetLocalNumber(string localNumber)
{
	this->localNumber = localNumber;
}


string PhoneNumber::GetNumber()
{
	return number;
}

void PhoneNumber::SetNumber(string number)
{
	this->number = number;
}


string PhoneNumber::GetCityName()
{
	return cityName;
}

void PhoneNumber::SetCityName(string cityName)
{
	this->cityName = cityName;
}
