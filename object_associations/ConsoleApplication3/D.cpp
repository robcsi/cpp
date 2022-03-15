#include "pch.h"
#include "D.h"
#include <iostream>

D::~D()
{
	std::cout << "~D()" << std::endl;
	setE(nullptr);
	setF(nullptr);
}
