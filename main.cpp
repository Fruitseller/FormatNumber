#include <iostream>
#include <string>
#include <algorithm>

#include "FormatNumber.h"


string inputString;
int main()
{
	FormatNumber* Formatter = new FormatNumber();
	PhoneNumber* MyPhoneNumber = new PhoneNumber();

	cout << "##############################################################################################" << endl;
	cout << "# Bitte geben Sie eine beliebige internationale Rufnummer ein und drücken Sie dann Enter.    #" << endl;
	cout << "# Die eingegebene Rufnummer wird dann in ein nationales Rufnummernformat umgewandelt.        #" << endl;
	cout << "# Beachten Sie bitte, dass nur korrekte internationale Rufnummern eingegeben werden dürfen.  #" << endl;
	cout << "# Bei fehlerhafter Nutzung kann ein korrekter Umwandlungsprozess nicht gewähleistet werden.  #" << endl;
	cout << "##############################################################################################" << endl;

	cout << "\nIhre internationale Rufnummer: ";
	getline(cin, inputString);

	/*
	while (!(ValidateNumber::ValidateInputOnCorrectness(inputString)))
	{
		cout << "Falsche Eingabe! Bitte wiederholen.";
		cout << "\nIhre internationale Rufnummer: ";
		cin >> inputString;
	}


	MyPhoneNumber = Formatter->FormatGlobalNumberToLocalNumber(inputString);

	cout << endl;
	cout << "Ländercode: " << MyPhoneNumber->GetCountryCode() << endl;
	cout << "Vorwahl:    " << MyPhoneNumber->GetAreaCode();
	cout << "  Stadt: " << MyPhoneNumber->GetCityName() << endl;
	cout << "Nummer:     " << MyPhoneNumber->GetNumber() << endl;
	cout << endl << MyPhoneNumber->GetLocalNumber();
	*/
	try
	{
		MyPhoneNumber = Formatter->ParsePhoneNumber(inputString);
	}
	catch (eFileStreamConverter& FileException)
	{
		cerr << "Bitte Programm neustarten!" << endl;
		cerr << FileException.what();
		terminate();
	}
	catch(eFormatNumber& FormatException)
	{
		cerr << "Bitte Programm neustarten!" << endl;
		cerr << FormatException.what();
		terminate();
	}

	if (!ValidateNumber::HasInputValidLength(MyPhoneNumber))
	{
		cerr << "Bitte Programm neustarten!" << endl;
		cerr << "Übergegebene Nummer hat falsche Länge." << endl;
	}
	else
	{
		cout << endl;
		cout << "Ländercode:               " << MyPhoneNumber->GetCountryCode() << endl;
		cout << "Vorwahl:                  " << MyPhoneNumber->GetAreaCode();
		cout << "  Stadt: " << MyPhoneNumber->GetCityName() << endl;
		cout << "Nummer:                   " << MyPhoneNumber->GetNumber() << endl;
		cout << "Internationale Rufnummer: " << MyPhoneNumber->GetGlobalNumber() << endl;
		cout << "Nationale Rufnummer:      " << MyPhoneNumber->GetLocalNumber() << endl;
		cout << endl;
	}

	delete MyPhoneNumber;
	delete Formatter;

	return 0;
}
