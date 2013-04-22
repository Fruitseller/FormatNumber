#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <mysql++.h>

#include "FormatNumber.h"
#include "ExceptionHandler.h"
#include "FormatMenu.h"
#include "TableView.h"
#include "TableModify.h"


string inputString;

int main()
{

	FormatNumber* Formatter = new FormatNumber();
	PhoneNumber* MyPhoneNumber = new PhoneNumber();
	mysqlpp::Connection* ConnectionObj = new mysqlpp::Connection(true);
	TableView* DBTableView = new TableView();
	TableModify* DBModifier = new TableModify();
	string area_code, city, country_code, country_name;


	FormatMenu::PrintMainMenu();

	while(true) {

		cout << "-------------------------------------------------------\n";
		cout << "Eingabe: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1:
				FormatMenu::PrintManual();

				cout << "\nIhre internationale Rufnummer: ";
				//ignore() is important because getline get all cin and not just this.
				cin.ignore();
				getline(cin, inputString);

				try
				{
					MyPhoneNumber = Formatter->ParsePhoneNumber(inputString);
					ValidateNumber::HasInputValidLength(MyPhoneNumber);
				}
				catch (exception& exc)
				{
					cerr << "Bitte Programm neustarten!" << endl;
					ExceptionHandler Handler(&exc);

					delete MyPhoneNumber;
					delete Formatter;
					return 0;
				}

				FormatMenu::PrintResult(MyPhoneNumber);
				break;

			case 2:
				if(ConnectionObj->connect("formatNumber", "localhost","sa", "peter01", 3306))
				{
					DBTableView->SetDbConnection(ConnectionObj);
					DBTableView->DumpResultsForTableCity(DBTableView->DumpCityTable());
					DBTableView->DumpResultsForTableAreaCode(DBTableView->DumpAreaCodeTable());
				}
				else
					cout << "Verbindung fehlgeschlagen\n";
				break;

			case 3:
				ConnectionObj->disconnect();
				cout << "Vorwahl eingeben: ";
				cin >> area_code;
				cout << "\nStadt eingeben: ";
				cin >> city;
				cout << "\nLandesvorwahl eingeben: ";
				cin >> country_code;
				cout << "\nLand eingeben: ";
				cin >> country_name;

				try
				{
					if(ConnectionObj->connect("format_number_DB", "localhost","root", "", 3306))
					{

						DBModifier->SetDBConnection(ConnectionObj);
						DBModifier->InsertAreaCode(area_code, city, country_code, country_name);
						//DBModifier->InsertCountryCode("86", "China");
						//DBModifier->InsertCountryCode("49", "Deutschland");
						//DBModifier->InsertAreaCode("10", "Peking", "86","China");
						//DBModifier->InsertAreaCode("222", "Köln", "49", "Deutschland");
					}
					else
						cout << "Verbindung fehlgeschlagen\n";
				}
				catch (exception& ex)
				{
					cerr << "Bitte Programm neustarten!" << endl;
					//ExceptionHandler DBExceptionHandler(&ex);
					cout << ex.what();

					return 0;
				}
				break;
			case 9:
				delete MyPhoneNumber;
				delete Formatter;
				cout << "Programm wurde beendet.";
				return 0;
		}
	}

	delete MyPhoneNumber;
	delete Formatter;
	delete ConnectionObj;
	delete DBTableView;
	delete DBModifier;

	return 0;
}
