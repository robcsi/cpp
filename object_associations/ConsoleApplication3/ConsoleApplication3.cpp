// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.fluentcpp.com/2017/12/12/mixin-classes-yang-crtp/

#include "pch.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include "CS.h"
#include "D.h"
#include "E.h"
#include "G.h"
#include "H.h"

#include "WaitingSignallable.h"
#include "StaticAtomicStoppable.h"

int main()
{
	//association 1-1 (both ways)
	A a;
	B b1;
	a.setB(&b1);
	B b2;
	b2.setA(&a);
	
	//association 1-n (both ways)
	Cs cs1;
	C c;
	Cs cs2;
	
	cs1.add(&c);
	c.setCS(&cs1);
	
	cs2.add(&c);
	
	//shared_ptr usage
	auto pE = std::make_shared<E>();
	auto pD = std::make_shared<D>();
	
	pE->setD(pD);
	pD->setE(pE);
	
	pE->setD(nullptr);
	pD->setE(nullptr);
	{
		//unique_ptr usage: you can simply get() the pointer from it and do whatever you want...
		auto f = std::make_unique<F>();
		pD->setF(f);
	}
	//you can also get a reference to a unique_ptr from inside a class (seems very dangerous)
	auto& zz = pD->getUniquePtrReference();

	//waitable and stoppable
	StaticWS mainThread;
	StaticAtomicStoppable workerThread(&mainThread);

	//https://awesomekling.github.io/Serenity-C++-patterns-The-Badge/ - how to decouple friendship from two classes, and how to restrict a method to be called for only one class
	H h; //class that wants/needs to be a friend
	H1 h1; //same here, but different badge type
	G g; //main class
	g.doSomethingForHOnly(H::getBadge(), h);
	g.doSomethingForH1Only(H1::getBadge(), h1);

	//g.doSomethingForH1Only(H::getBadge(), h); //compile error
}
