#pragma once
#include "windows.h"
#include "Signallable.h"
#include "StaticAtomicStoppable.h"

template <typename Stoppable>
class WaitingSignallable : public Signallable
{
public:
	void notifyAllStoppables()
	{
		Stoppable::stop();
	}

	void signalStopEvent()
	{
		if (m_stopEvent)
			::SetEvent(m_stopEvent);
	}

protected:
	WaitingSignallable(const unsigned int& timeout = 5000)
		: Signallable(),
		m_stopEvent(nullptr),
		m_timeout(timeout)
	{
		m_stopEvent = ::CreateEvent(nullptr, true, false, nullptr);
	}

	virtual ~WaitingSignallable() = 0
	{
		if (m_stopEvent)
			::CloseHandle(m_stopEvent);
	}

	virtual void wait()
	{
		assert(!"Method not implemented in derived class: please override by calling internalWait(), and call wait() method in derived destructor!");
	}

	void internalWait()
	{
		if (m_stopEvent)
			::WaitForSingleObject(m_stopEvent, m_timeout);
	}

private:
	HANDLE m_stopEvent;
	unsigned int m_timeout;
};


class StaticWS : public WaitingSignallable<StaticAtomicStoppable>
{
public:
	StaticWS(const unsigned int& timeout = INFINITE) : WaitingSignallable<StaticAtomicStoppable>(timeout) {}
	~StaticWS()
	{ 
		wait();
	}

private:
	void wait()
	{
		__super::internalWait();
	}
};

