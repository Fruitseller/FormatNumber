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
	cin >> inputString;

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
		/*
		cout << endl;
		cout << "Ländercode:            " << MyPhoneNumber->GetCountryCode() << endl;
		cout << "Vorwahl:               " << MyPhoneNumber->GetAreaCode();
		cout << "  Stadt: " << MyPhoneNumber->GetCityName() << endl;
		cout << "Nummer:                " << MyPhoneNumber->GetNumber() << endl;
		cout << "Internationale Rufnummer: " << MyPhoneNumber->GetGlobalNumber() << endl;
		cout << "Nationale Rufnummer:      " << MyPhoneNumber->GetLocalNumber() << endl;
		cout << endl;
		*/
	}
	catch (const eOnkzFileStream& FileException)
	{
		cerr << "Datei konnte nicht gelesen werden." << endl;
		cerr << "Bitte Programm neustarten!" << endl;
		terminate();
	}
	catch(const eFormatNumber& FormatException)
	{
		cerr << "Rufnummer konnte nicht richtig formatiert werden." << endl;
		cerr << "Bitte Programm neustarten!" << endl;
		terminate();
	}

	MyPhoneNumber = NULL;
	cout << endl;
	cout <<
	cout << "Ländercode:            " << MyPhoneNumber->GetCountryCode() << endl;
	cout << "Vorwahl:               " << MyPhoneNumber->GetAreaCode();
	cout << "  Stadt: " << MyPhoneNumber->GetCityName() << endl;
	cout << "Nummer:                " << MyPhoneNumber->GetNumber() << endl;
	cout << "Internationale Rufnummer: " << MyPhoneNumber->GetGlobalNumber() << endl;
	cout << "Nationale Rufnummer:      " << MyPhoneNumber->GetLocalNumber() << endl;
	cout << endl;

	delete MyPhoneNumber;
	delete Formatter;

	return 0;
}
