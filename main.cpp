#include <iostream>
#include <string>
#include <algorithm>

#include "FormatNumber.h"

string inputstring, outputstring;
int main()
{
	FormatNumber *Formatter = new FormatNumber();
	cin >> inputstring;
	cout << Formatter->FormatGlobalNumberToLocalNumber(inputstring);
	cout << "Hallo";
	delete Formatter;

	return 0;
}

