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
	//ifstream InitializeFileStream();
	map<string, string> GetMapFromStream(ifstream fileStream);
	map<string, string> CreateMapWithOnkz();
	string FindCityNameFromMap(map<string, string> onkzMapList, string areaCode);
};


#endif /* ONKZFILESTREAM_H_ */
