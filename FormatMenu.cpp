/*
 * FormatMenu.cpp
 *
 *  Created on: 18.02.2013
 *      Author: bronkalla
 */

#include "FormatMenu.h"


void FormatMenu::PrintMainMenu()
{
	cout << "#######################################################" << endl;
	cout << "#           --------->Hauptmenü<---------             #" << endl;
	cout << "#######################################################" << endl;
	cout << "# Bitte wählen Sie aus den folgenden Optionen:        #" << endl;
	cout << "# 1 für Formatierung einer internationalen Rufnummer. #" << endl;
	cout << "# 2 für Abfragen Datenbankrelevanter Informationen.   #" << endl;
	cout << "# 9 für Programm beenden.                             #" << endl;
	cout << "#######################################################" << endl;
}


void FormatMenu::PrintManual()
{
	cout << "##############################################################################################" << endl;
	cout << "# Bitte geben Sie eine beliebige internationale Rufnummer ein und drücken Sie dann Enter.    #" << endl;
	cout << "# Die eingegebene Rufnummer wird dann in ein nationales Rufnummernformat umgewandelt.        #" << endl;
	cout << "# Beachten Sie bitte, dass nur korrekte internationale Rufnummern eingegeben werden dürfen.  #" << endl;
	cout << "# Bei fehlerhafter Nutzung kann ein korrekter Umwandlungsprozess nicht gewährleistet werden. #" << endl;
	cout << "##############################################################################################" << endl;
}

/**
PhoneNumber* StartFormating(FormatNumber* Formatter, PhoneNumber* Number, string input)
{

	try
	{
		Number = Formatter->ParsePhoneNumber(input);
		ValidateNumber::HasInputValidLength(Number);
	}
	catch (exception& exc)
	{
		cerr << "Bitte Programm neustarten!" << endl;
		ExceptionHandler Handler(&exc);

		delete Number;
		delete Formatter;

		return 1;
	}

	return Number;
}
*/

void FormatMenu::PrintResult(PhoneNumber* Number)
{
	cout << endl;
	cout << "Ländercode:               " << Number->GetCountryCode() << endl;
	cout << "Vorwahl:                  " << Number->GetAreaCode();
	cout << "  Stadt: " << Number->GetCityName() << endl;
	cout << "Nummer:                   " << Number->GetNumber() << endl;
	cout << "Internationale Rufnummer: " << Number->GetGlobalNumber() << endl;
	cout << "Nationale Rufnummer:      " << Number->GetLocalNumber() << endl;
	cout << endl;
}



