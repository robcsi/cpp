#pragma once
#include <atomic>

class Signallable;

class StaticAtomicStoppable
{
public:
	StaticAtomicStoppable(Signallable* pSignallable);
	virtual ~StaticAtomicStoppable();

	static void stop();
	void signalStop();
	static bool canContinue() { return m_canContinue; }
protected:
	static std::atomic_bool m_canContinue;
private:
	Signallable* pSignallable;
};

