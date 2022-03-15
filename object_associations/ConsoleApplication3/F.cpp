#include "pch.h"
#include "F.h"
#include <iostream>


F::~F()
{
	std::cout << "~F()" << std::endl;
	setD(nullptr);
}
