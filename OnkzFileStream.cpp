/*
 * OnkzFileStream.cpp
 *
 *  Created on: 19.11.2012
 *      Author: bronkalla
 */


#include "OnkzFileStream.h"

using namespace std;



map<string, string> OnkzFileStream::GetMapFromFileDirectory(const char* fileDirectory)
{
	string cityName;
	string lineTmpString;
	size_t pos;
	string tmp;
	map<string, string> onkzMapList;


	ifstream fileStream(fileDirectory);

	if (!fileStream)
	{
		throw eOnkzFileStream();
	}


	while (getline(fileStream, lineTmpString))
	{
		if (lineTmpString.at(0) != '#')
		{
			for (unsigned int i = 0; i < lineTmpString.length(); i++)
			{
				if (lineTmpString.at(i) == ';')
				{

					//tmp = "0" + tmp;
					onkzMapList[tmp];
					pos = lineTmpString.find(';');

					onkzMapList[tmp] = lineTmpString.substr(pos + 1);

					i = lineTmpString.length();
					/**
					 * Debug Infos
					 * cout << "Map[" << tmp << "]: " << onkzMapList[tmp] << endl;
					 */
					tmp = "";
				}
				else
				{
					tmp += lineTmpString.at(i);
				}
			}
		}
	}
	fileStream.close();

	return onkzMapList;
}


string OnkzFileStream::FindCityNameFromMap(map<string, string> onkzMapList, string areaCode)
{
	string cityName;

	if (onkzMapList.find(areaCode) != onkzMapList.end())
	{
		cityName = onkzMapList.find(areaCode)->second;
	}
	else
	{
		cityName = "Keine passende Stadt gefunden!";
	}
	/**
	 * Debug infos
	 * cout << "02131: " << onkzMapList.find("02131")->second << endl;
	 */
	return cityName;
}


map<string, string> OnkzFileStream::LoadCCMap()
{
	const char* path;
	path = "/home/bronkalla/workspace/FormatNumber/src/countrycodes.txt";
	return GetMapFromFileDirectory(path);
}


map<string, string> OnkzFileStream::LoadACMapFromCC(string countryCode)
{
	const char* path;
	countryCode = "/home/bronkalla/workspace/FormatNumber/src/areacode" + countryCode + ".txt";
	path = countryCode.c_str();
	return GetMapFromFileDirectory(path);
}
