#pragma once
class A;
class B
{
public:
	B();
	~B();
	void setA(A* newB);
private:
	A* a;
};

