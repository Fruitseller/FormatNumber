#include <iostream>
#include <string>
#include <algorithm>

#include "FormatNumber.h"

string inputString, outputString;
int main()
{
	FormatNumber *Formatter = new FormatNumber();

	cout << "Bitte geben Sie eine beliebige internationale Rufnummer ein und drücken Sie dann Enter." << endl;
	cout << "Die eingegebene Rufnummer wird dann in ein nationales Rufnummernformat umgewandelt." << endl;
	cout << "Beachten Sie bitte, dass nur korrekte internationale Rufnummern eingegeben werden dürfen." << endl;
	cout << "Bei fehlerhafter Benutzung kann ein korrekter Umwandlungsrozess nicht gewähleistet werden." << endl;
	cout << "\nIhre internationale Rufnummer: ";
	cin >> inputString;
	outputString = Formatter->FormatGlobalNumberToLocalNumber(inputString);
	cout << endl;
	delete Formatter;

	return 0;
}

