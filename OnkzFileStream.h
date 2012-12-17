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
	/**
	 * First Create ifstream based on given fileDirectory. Iterate on Stream an write informations to std::Map
	 *
	 * @param const char* with directory where the file can be found
	 * @return map<string, string> filled with map<onkzNumber, cityName> based on the onkz File
	 *
	 * @throw eOnkzFileStream
	 */
	static map<string, string> GetMapFromFileDirectory(const char* fileDirectory);


	/**
	 * Search given areaCode in the given map
	 *
	 * @param map<string, string> filled with onkz Data , string with areaCode of a number
	 * @return string cityName based on found onkz in map. When nothing found then "Keine passende Stadt gefunden!"
	 */
	static string FindCityNameFromMap(map<string, string> onkzMapList, string areaCode);


	/**
	 * Call GetMapFromFileDirectory() with path to countrycode.txt
	 *
	 * @return map<string, string> created from countrycodes.txt
	 */
	static map<string, string> LoadCCMap();


	/**
	 * Call GetMapFromFileDirectory() with path to *.txt based on input
	 *
	 * @param string countryCode
	 * @return map<string, string> created from *.txt which is based on countryCode.
	 */
	static map<string, string> LoadACMapFromCC(string countryCode);
};


#endif /* ONKZFILESTREAM_H_ */
