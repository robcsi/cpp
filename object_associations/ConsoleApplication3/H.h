#pragma once

//https://awesomekling.github.io/Serenity-C++-patterns-The-Badge/
template<typename FriendType>
class Badge
{
private:
	friend FriendType;
	Badge() {}
};

//simplest solution (no base class or anything else)
class H
{
public:
	typedef typename Badge<H> BadgeType;

	H();
	~H();

	static BadgeType getBadge() { return s_badge; }
private:
	static BadgeType s_badge;
};


//trying to generalize all this below: impossible to put the getBadge method into the base class without reimplementing it in the derived class.
// this is because the Badge class needs to be friends with the derived class, not the base-class, and we are creating a new object, not calling a derived class method.
// we could call a derived class method, but it would not be the point of the exercise....

//CRTP-like pattern
template<typename T>
class HasBadge
{
public:
	typedef typename Badge<T> BadgeType;

	static BadgeType getBadge() { return s_badge; }
protected:
	HasBadge () {}
	virtual ~HasBadge () {}

	static BadgeType s_badge;
};

//best possible solution, because we separate the functionality of Badge-ness to the base class
class H1 : public HasBadge<H1>
{
public:
	H1() : HasBadge() {}
	~H1() {}
};

// --------------------- other possibilities and their disadvantages -----------------------

//Mixin - no sense in this case really, because the value that needs to be wrapped by a mixin does not exist;
// our class only creates something
class H2
{
public:
	H2() {}
	~H2() {}

	Badge<H2> createBadge() { return {}; }
};

template<typename T>
class FriendlyT : T
{
	explicit FriendlyT(T const& t) : T(t) {}

	Badge<T> getBadge() { this->createBadge(); }
};

//usage:
// FriendlyT<H2> fh2 (h2); //not good, an h2 must exist first...
// fh2.getGadge();
