#include "pch.h"
#include "Cs.h"
#include "C.h"
#include <algorithm>

Cs::Cs()
{
}

Cs::~Cs()
{
	std::for_each(cs.begin(), cs.end(), [this](C* c) { remove(c); });
}

void Cs::add(C* newC)
{
	//return if we want to add a nullptr
	if (newC == nullptr)
	{
		return;
	}
	
	//find if already exists
	auto it = std::find(cs.begin(), cs.end(), newC);
	if (it == cs.end())
	{
		//set old parent to nullptr
		newC->setCS(nullptr);
		
		//if not, add to list
		cs.push_back(newC);

		//set new container as parent
		newC->setCS(this);
	}
}

void Cs::remove(C* newC)
{
	//return if we want to remove a nullptr (adding is not allowed)
	if (newC == nullptr)
	{
		return;
	}

	//find if we already contain it
	auto it = std::find(cs.begin(), cs.end(), newC);
	if (it != cs.end())
	{
		//remove from list
		cs.erase(it);
		//set new parent as nullptr
		newC->setCS(nullptr);
	}
}
