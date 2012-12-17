/*
 * PrefixContainer.cpp
 *
 *  Created on: 04.12.2012
 *      Author: bronkalla
 */

#include "PrefixContainer.h"



string PrefixContainer::GetPrefix()
{
	return prefix;
}

void PrefixContainer::SetPrefix(string prefix)
{
	this->prefix = prefix;
}


string PrefixContainer::GetRemainder()
{
	return remainder;
}

void PrefixContainer::SetRemainder(string remainder)
{
	this->remainder = remainder;
}
