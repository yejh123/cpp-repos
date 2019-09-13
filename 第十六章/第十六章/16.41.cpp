#include <iostream>
#include <typeinfo>
using namespace std;
template <typename T1, typename T2 >
auto f(T1 a, T2 b) -> decltype(a + b)
{
	return a + b;
}
int main()
{
	__int64 a;
	long long b;
	cout << sizeof(a) << '\t' << sizeof(b) << endl;
	cout << f(2100000000, 10000000000000000) << endl;
	cout << typeid(f(2100000000, 10000000000000000)).name() << endl;    //__int64(long long)
}