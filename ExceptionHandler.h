/*
 * ExceptionHandler.h
 *
 *  Created on: 08.01.2013
 *      Author: bronkalla
 */

#ifndef EXCEPTIONHANDLER_H_
#define EXCEPTIONHANDLER_H_

#include <iostream>
#include <string>
#include <exception>
#include <typeinfo>

#include "eFormatNumber.h"
#include "eFileStreamConverter.h"
#include "eFalseNumberLength.h"
#include "eDatabaseInsertion.h"

using namespace std;

class ExceptionHandler
{
public:
	/**
	 * Default non parameter constructor
	 */
	ExceptionHandler();

	/**
	 * Check what type of exception was given, convert to this exception subclass and call its what()
	 */
	ExceptionHandler(exception*);

	/**
	 * Use dynamic_cast to convert from exception to eFormatNumber
	 *
	 * @param std::exception
	 * @return eFormatNumber class
	 */
	eFormatNumber* ConvertExceptionToeFormatNumber(exception*);

	/**
	 * Use dynamic_cast to convert from exception to eFileStreamConverter
	 *
	 * @param std::exception
	 * @return eFileStreamConverter class
	 */
	eFileStreamConverter* ConvertExceptionToeFileStreamConverter(exception*);

	/**
	 * Use dynamic_cast to convert from exception to eFalseNumberLength
	 *
	 * @param std::exception
	 * @return eFalseNumberLength class
	 */
	eFalseNumberLength* ConvertExceptionToeFalseNumberLength(exception*);


	eDatabaseInsertion* ConvertExceptionToeDatabaseInsertion(exception*);

};


#endif /* EXCEPTIONHANDLER_H_ */
