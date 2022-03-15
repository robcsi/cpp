#pragma once
#include "assert.h"

class Signallable
{
public:
	virtual void signalStopEvent()
	{
		assert(!"Method not implemented: please override in derived class!");
	}
protected:
	Signallable() {}
	virtual ~Signallable() = 0 {};
};
