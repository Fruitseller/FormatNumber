#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <mysql++.h>

#include "FormatNumber.h"
#include "ExceptionHandler.h"
#include "FormatMenu.h"
#include "TableView.h"


string inputString;

int main()
{

	FormatNumber* Formatter = new FormatNumber();
	PhoneNumber* MyPhoneNumber = new PhoneNumber();

	mysqlpp::Connection* ConnectionObj = new mysqlpp::Connection(true);

	TableView* DBTableView = new TableView();

	while(true) {

		FormatMenu::PrintMainMenu();
		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1:
				FormatMenu::PrintManual();

				cout << "\nIhre internationale Rufnummer: ";

				/**
				 * ignore() is important because getline get all cin and not just this.
				 */
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

					return 1;
				}

				FormatMenu::PrintResult(MyPhoneNumber);
				break;

			case 2:
				if(ConnectionObj->connect("formatNumber", "localhost","sa", "peter01", 3306))
				{
					DBTableView->SetDbConnection(ConnectionObj);
					DBTableView->DumpCityTable();
					DBTableView->DumpAreaCodeTable();

				}
				else
					cout << "Verbindung fehlgeschlagen\n";
				break;

			case 9:
				delete MyPhoneNumber;
				delete Formatter;
				cout << "Programm wurde beendet.";
				return 1;
		}
	}

	delete MyPhoneNumber;
	delete Formatter;
	delete ConnectionObj;
	delete DBTableView;

	return 0;
}
