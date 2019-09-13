#include<iostream>
#include<utility>
using namespace std;
void f(int v1, int &v2)
{
	cout << v1 << " " << ++v2 << endl;
}
void g(int &&i, int & j)
{
	cout << i << " " << j << endl;
}
template <typename F, typename T1, typename T2>
void filp(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T1>(t1), std::forward<T2>(t2));
}
int main()
{
	int i = 42;
	filp(f, 42, i);          //第一个参数必须是右值，第二个参数必须是左值
	cout << i << endl;
}