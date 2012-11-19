/*
 * OnkzFileStream.cpp
 *
 *  Created on: 19.11.2012
 *      Author: bronkalla
 */


#include "OnkzFileStream.h"

using namespace std;

/*
ifstream OnkzFileStream::InitializeFileStream()
{
	ifstream fileStream("/home/bronkalla/workspace/FormatNumber/src/onkz.txt");

	if (!fileStream)
	{
		cerr << "LOL alles kaputt";
	}

	return fileStream;

}
*/

map<string, string> OnkzFileStream::GetMapFromStream(ifstream fileStream)
{
	string cityName;
	string lineTmpString;
	size_t pos;
	string tmp;
	vector<string> tmpVectorOfLines;
	unsigned int lineCounter(0);
	map<string, string> onkzMapList;



	while (getline(fileStream, lineTmpString))
	{
		if (lineTmpString.at(0) != '#')
			tmpVectorOfLines.push_back(lineTmpString);
	}
	fileStream.close();
	/**
	 * Debug infos
	 * cout << "vector[0]: " << tmpVectorOfLines[0] << endl;
	 * cout << "vector.back(): " << tmpVectorOfLines.back() << endl;
	 * cout << "vector[5204]: " << tmpVectorOfLines[5204] << endl;
	 * cout << "size: " << tmpVectorOfLines.size() << endl;
	 */

	for (; lineCounter < tmpVectorOfLines.size(); lineCounter++)
	{

		for (unsigned int i = 0; i < tmpVectorOfLines[lineCounter].length(); i++)
		{
			if (tmpVectorOfLines[lineCounter].at(i) == ';')
			{

				tmp = "0" + tmp;
				onkzMapList[tmp];
				pos = tmpVectorOfLines[lineCounter].find(';');

				onkzMapList[tmp] = tmpVectorOfLines[lineCounter].substr(pos + 1);

				i = tmpVectorOfLines[lineCounter].length();

				/**
				 * Debug infos
				 * cout << "Map[" << tmp << "]: " << onkzMapList[tmp] << endl;
				 */
				tmp = "";
			}
			else
			{
				tmp += tmpVectorOfLines[lineCounter].at(i);
			}
		}
	}


	return onkzMapList;
}

map<string, string> OnkzFileStream::CreateMapWithOnkz()
{
	map<string, string> onkzMapList;



	ifstream fileStream("/home/bronkalla/workspace/FormatNumber/src/onkz.txt");

	if (!fileStream)
	{
		cerr << "LOL alles kaputt";
	}

	//fileStream = InitializeFileStream();
	onkzMapList = GetMapFromStream(fileStream);

	return onkzMapList;
}

string OnkzFileStream::FindCityNameFromMap(map<string, string> onkzMapList, string areaCode)
{
	string cityName;

	cityName = onkzMapList.find(areaCode)->second;
	/**
	 * Debug infos
	 * cout << "02131: " << onkzMapList.find("02131")->second << endl;
	 */
	return cityName;
}
