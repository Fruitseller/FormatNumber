/*
 * eFormatNumber.h
 *
 *  Created on: 10.12.2012
 *      Author: bronkalla
 */

#ifndef EFORMATNUMBER_H_
#define EFORMATNUMBER_H_

#include <iostream>
#include <exception>
#include <string>


using namespace std;

class eFormatNumber : public exception
{
public:
	eFormatNumber();


	/**
	 * Write message + string in global string msg.
	 */
	eFormatNumber(string);


	~eFormatNumber() throw();


	virtual const char* what() throw();

private:
	string msg;
};


#endif /* EFORMATNUMBER_H_ */
