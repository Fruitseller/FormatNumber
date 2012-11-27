/*
 * OnkzFileStream.h
 *
 *  Created on: 19.11.2012
 *      Author: bronkalla
 */

#ifndef ONKZFILESTREAM_H_
#define ONKZFILESTREAM_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "eOnkzFileStream.h"

using namespace std;

class OnkzFileStream
{

public:
	static map<string, string> GetMapFromFileDirectory(const char* filedirectory);
	static string FindCityNameFromMap(map<string, string> onkzMapList, string areaCode);

private:

};


#endif /* ONKZFILESTREAM_H_ */
