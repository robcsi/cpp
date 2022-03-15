#include "pch.h"
#include "C.h"
#include "Cs.h"


C::C() : cs(nullptr)
{
}

C::~C()
{
	if (cs)
	{
		cs->remove(this);
	}
}

void C::setCS(Cs* newCS)
{
	//not allowing the same parent to be set again
	if (cs == newCS)
	{
		return;
	}
	
	if (cs)
	{
		//if parent set, remove from old parent first
		cs->remove(this);
	}

	//set new parent
	cs = newCS;

	if (cs != nullptr)
	{
		//add this to new parent
		cs->add(this);
	}
}
