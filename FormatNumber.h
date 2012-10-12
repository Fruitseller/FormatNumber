#ifndef FORMATNUMBER_H
#define FORMATNUMBER_H

#include <string>

using namespace std;

class FormatNumber
{
public:
	bool IsInputNotEmptyAndDigit(string const &input);
	string FormatGlobalNumberToLocalNumber(string input);

};

#endif
