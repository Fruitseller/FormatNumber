/*
 * FormatMenu.h
 *
 *  Created on: 18.02.2013
 *      Author: bronkalla
 */

#ifndef FORMATMENU_H_
#define FORMATMENU_H_

#include <iostream>
#include <string>

#include "FormatNumber.h"
#include "ExceptionHandler.h"


using namespace std;

class FormatMenu
{
public:
	static void PrintMainMenu();
	static void PrintManual();
	//PhoneNumber* StartFormating(FormatNumber*, PhoneNumber*,string);
	static void PrintResult(PhoneNumber*);

};

#endif /* FORMATMENU_H_ */
