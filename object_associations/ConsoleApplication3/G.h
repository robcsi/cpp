#pragma once

#include "H.h"

class G
{
public:
	G();
	~G();

	void doSomethingForHOnly(H::BadgeType, H&) {}
	void doSomethingForH1Only(H1::BadgeType, H1&) {}
};

