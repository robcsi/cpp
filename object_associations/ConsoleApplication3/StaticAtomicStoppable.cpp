#include "StaticAtomicStoppable.h"
#include "Signallable.h"

std::atomic_bool StaticAtomicStoppable::m_canContinue = true;

StaticAtomicStoppable::StaticAtomicStoppable(Signallable* ptr):
	pSignallable(ptr)
{
}

StaticAtomicStoppable::~StaticAtomicStoppable()
{
	signalStop();
	pSignallable = nullptr;
}

void StaticAtomicStoppable::stop()
{
	m_canContinue = false;
}

void StaticAtomicStoppable::signalStop()
{
	if (pSignallable)
	{
		pSignallable->signalStopEvent();
	}
}
