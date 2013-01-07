/*
 * eOnkzFileStream.h
 *
 *  Created on: 26.11.2012
 *      Author: bronkalla
 */

#ifndef EFILESTREAMCONVERTER_H_
#define EFILESTREAMCONVERTER_H_

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class eFileStreamConverter : public exception
{
public:
	virtual const char* what() throw();
};


#endif /* EFILESTREAMCONVERTER_H_ */
