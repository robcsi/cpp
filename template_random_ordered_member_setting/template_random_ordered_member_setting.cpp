#include <string>

using namespace std;

#define SAF_GEN_MEMBER(base, name, type)\
class base##_##name\
{\
public:\
	typedef typename type InnerType;\
\
	base##_##name(const InnerType& val) : innerValue(val) {}\
	InnerType innerValue;\
};\
\
class base;\
\
template <typename T, typename U> \
class has_##name \
{\
public:\
	T& operator<<(const U& value) \
	{ \
		T& retVal = static_cast<T&>(*this); \
		retVal.m_##name = value.innerValue; \
		return retVal; \
	} \
	const typename U::InnerType& get##name() const { \
		return m_##name; \
	} \
private: \
	typename U::InnerType m_##name{}; \
}; \
\
using m_##name = has_##name < base, base##_##name >; \

SAF_GEN_MEMBER(AAA, SessionID, string)
SAF_GEN_MEMBER(AAA, Name, string)
SAF_GEN_MEMBER(AAA, TickCount, int)

class AAA :
	public m_SessionID,
	public m_Name,
	public m_TickCount
{

};

int main()
{
	AAA a;
	a << AAA_Name{ "Robi" } << AAA_TickCount{ 3000 } << AAA_SessionID{ "123" };
	auto t = a.getTickCount();
	auto s = a.getSessionID();
	auto n = a.getName();
    return 0;
}

