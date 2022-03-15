#include "pch.h"
#include "E.h"
#include <iostream>

E::~E()
{
	std::cout << "~E()";
	setD(nullptr);
}
