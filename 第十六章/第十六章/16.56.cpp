#include<iostream>
using namespace std;
template<typename T>
ostream &print(ostream&os, const T &t);
template<typename T, typename ... Args>
ostream &print(ostream&os, const T &t, const Args & ...rest)
{
	os << t << ", ";
	return print(os, rest...);
}
template<typename T>
ostream &print(ostream&os, const T &t)
{
	return os << t;

}
template<typename ...Args>
ostream &erroeMsg(ostream &os, const Args& ...rest)
{
	return print(os, )
}
int main()
{
	print(cout, 5, "fuck", 42, 's', 9.4);
}