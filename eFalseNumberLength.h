/*
 * eFalseNumberLength.h
 *
 *  Created on: 14.01.2013
 *      Author: bronkalla
 */

#ifndef EFALSENUMBERLENGTH_H_
#define EFALSENUMBERLENGTH_H_

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class eFalseNumberLength : public exception
{

public:
	virtual const char* what()throw();
};


#endif /* EFALSENUMBERLENGTH_H_ */
