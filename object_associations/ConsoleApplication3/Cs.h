#pragma once
#include <vector>

class C;
class Cs
{
public:
	Cs();
	~Cs();
	void add(C* newB);
	void remove(C* newB);
private:
	std::vector<C*> cs;
};

