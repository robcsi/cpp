#pragma once
#include <memory>
#include "F.h"
class E;

class Z
{
public:
	void aa() {}
};

class D 
{
public:
	D() : pE(nullptr), f(nullptr), aa(nullptr)
	{
		aa = std::make_unique<Z>();
	}
	~D();

	void setE(std::shared_ptr<E> ptr) { pE = ptr; }

	void setF(const std::unique_ptr<F>& pF)
	{
		f = nullptr;
		if (pF)
		{
			pF->setD(this);
			f = pF.get();  //just get() the pointer inside a unique_ptr if you want...
		}
	}

	const std::unique_ptr<Z>& getUniquePtrReference() const { return aa; }

private:
	std::shared_ptr<E> pE;
	F* f;
	std::unique_ptr<Z> aa;
};

