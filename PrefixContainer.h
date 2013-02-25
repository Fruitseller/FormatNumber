/*
 * PrefixContainer.h
 *
 *  Created on: 04.12.2012
 *      Author: bronkalla
 */

#ifndef PREFIXCONTAINER_H_
#define PREFIXCONTAINER_H_

#include <iostream>
#include <string>

using namespace std;

class PrefixContainer
{
public:
	string GetPrefix();


	void SetPrefix(string);


	string GetRemainder();


	void SetRemainder(string);
private:
	string prefix;
	string remainder;
};


#endif /* PREFIXCONTAINER_H_ */
