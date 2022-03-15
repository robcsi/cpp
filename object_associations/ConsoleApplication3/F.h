#pragma once
class D;
class F
{
public:
	F() : pD(nullptr) {}
	~F();
	void setD(D* d) { pD = d; }
private:
	D* pD;
};

