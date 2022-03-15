#include "pch.h"
#include "A.h"
#include "B.h"

A::A() : b(nullptr)
{
}

A::~A()
{
	setB(nullptr);
}

void A::setB(B* newB)
{
	//return if the same object is being set again
	if (b == newB)
	{
		return;
	}
	
	B* oldB = b;

	b = newB; //set new one
	
	if (oldB)
	{
		//if set, remove connection to old object
		oldB->setA(nullptr);
	}
	
	if (newB != nullptr)
	{
		//notifiy new object of the same connection
		newB->setA(this);
	}
}
