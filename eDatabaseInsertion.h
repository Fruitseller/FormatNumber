/*
 * eDatabaseInsertion.h
 *
 *  Created on: 04.04.2013
 *      Author: bronkalla
 */

#ifndef EDATABASEINSERTION_H_
#define EDATABASEINSERTION_H_

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class eDatabaseInsertion : public exception
{

public:
	virtual const char* what()throw();
};


#endif /* EDATABASEINSERTION_H_ */
