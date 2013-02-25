/*
 * eFormatNumber.cpp
 *
 *  Created on: 10.12.2012
 *      Author: bronkalla
 */

#include "eFormatNumber.h"


eFormatNumber::eFormatNumber()
{
	msg = "Fehler beim formatieren";
}


eFormatNumber::eFormatNumber(string leftover)
{
	msg = "Folgende Nummer konnte nicht gefunden werden: " + leftover;
}


eFormatNumber::~eFormatNumber() throw()
{

}


const char* eFormatNumber::what() throw()
{
	return msg.c_str();
}


