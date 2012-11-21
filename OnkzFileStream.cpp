/*
 * OnkzFileStream.cpp
 *
 *  Created on: 19.11.2012
 *      Author: bronkalla
 */


#include "OnkzFileStream.h"

using namespace std;



map<string, string> OnkzFileStream::GetMapFromStream()
{
	string cityName;
	string lineTmpString;
	size_t pos;
	string tmp;
	map<string, string> onkzMapList;


	ifstream fileStream("/home/bronkalla/workspace/FormatNumber/src/onkz.txt");

	if (!fileStream)
	{
		cerr << "LOL alles kaputt";
	}


	while (getline(fileStream, lineTmpString))
	{
		if (lineTmpString.at(0) != '#')
		{
			for (unsigned int i = 0; i < lineTmpString.length(); i++)
			{
				if (lineTmpString.at(i) == ';')
				{

					tmp = "0" + tmp;
					onkzMapList[tmp];
					pos = lineTmpString.find(';');

					onkzMapList[tmp] = lineTmpString.substr(pos + 1);

					i = lineTmpString.length();

					/**
					 * Debug infos
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
