#include "pch.h"
#include "B.h"
#include "A.h"

B::B(): a(nullptr)
{
}

B::~B()
{
	//remove current connection
	setA(nullptr);
}

void B::setA(A* newA)
{
	//return if the same object is being set again
	if (a == newA)
	{
		return;
	}
	
	A* oldA = a;
	
	//set new object
	a = newA;
	
	if (oldA)
	{
		//if set remove connection to old object
		oldA->setB(nullptr);
	}
	
	if (newA != nullptr)
	{
		//notifiy new object of the same connection
		newA->setB(this);
	}
}
