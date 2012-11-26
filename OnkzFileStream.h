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

/**
 * TODO
 * alles static machen???
 */
class OnkzFileStream
{

public:
	map<string, string> GetMapFromFileStream();
	string FindCityNameFromMap(map<string, string> onkzMapList, string areaCode);
	const char* GetFileDirectory();
	void SetFileDirectory(const char* areaCode);

private:
	const char* fileDirectory;
};


#endif /* ONKZFILESTREAM_H_ */
