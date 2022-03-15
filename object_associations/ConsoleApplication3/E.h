#pragma once
#include <memory>
class D;
class E
{
public:
	E() : pD(nullptr) {}
	~E();
	void setD(std::shared_ptr<D> ptr) { pD = ptr; }
private:
	std::shared_ptr<D> pD;
};

