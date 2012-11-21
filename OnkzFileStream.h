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

using namespace std;

class OnkzFileStream
{

public:
	map<string, string> GetMapFromStream();
	string FindCityNameFromMap(map<string, string> onkzMapList, string areaCode);
};


#endif /* ONKZFILESTREAM_H_ */
