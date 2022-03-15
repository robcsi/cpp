#pragma once
class B;
class A
{
public:
	A();
	~A();
	void setB(B* newB);
private:
	B* b;
};

