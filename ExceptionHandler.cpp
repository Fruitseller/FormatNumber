/*
 * ExceptionHandler.cpp
 *
 *  Created on: 08.01.2013
 *      Author: bronkalla
 */

#include "ExceptionHandler.h"

ExceptionHandler::ExceptionHandler()
{

}


ExceptionHandler::ExceptionHandler(exception* Error)
{
	if(typeid(*Error) == typeid(eFormatNumber))
	{
		eFormatNumber* FormatNumberException = ConvertExceptionToeFormatNumber(Error);
		cerr << FormatNumberException->what();
	}
	else if (typeid(*Error) == typeid(eFileStreamConverter))
	{
		eFileStreamConverter* FileStreamConverterException = ConvertExceptionToeFileStreamConverter(Error);
		cerr << FileStreamConverterException->what();
	}
	else if (typeid(*Error) == typeid(eFalseNumberLength))
	{
		eFalseNumberLength* FalseNumberLengthException = ConvertExceptionToeFalseNumberLength(Error);
		cerr << FalseNumberLengthException->what();
	}

	Error->what();

}


eFormatNumber* ExceptionHandler::ConvertExceptionToeFormatNumber(exception* e)
{
	eFormatNumber* FormatNumberException;
	FormatNumberException = dynamic_cast<eFormatNumber*>(e);
	return FormatNumberException;
}


eFileStreamConverter* ExceptionHandler::ConvertExceptionToeFileStreamConverter(exception* e)
{
	eFileStreamConverter* FileStreamConverterException;
	FileStreamConverterException = dynamic_cast<eFileStreamConverter*>(e);
	return FileStreamConverterException;
}


eFalseNumberLength* ExceptionHandler::ConvertExceptionToeFalseNumberLength(exception* e)
{
	eFalseNumberLength* FalseNumberLengthException;
	FalseNumberLengthException = dynamic_cast<eFalseNumberLength*>(e);
	return FalseNumberLengthException;
}
