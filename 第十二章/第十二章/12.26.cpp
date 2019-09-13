#include <iostream>
#include <memory>
#include <string>
using namespace std;
int main()
{
	int n = 10;
	allocator<string> a;
	auto const p0= a.allocate(n);           //const 不能少
	string * p = p0;
	string s;
	while (cin >> s && p0 != p + n) {
		a.construct(p++, s);
	}
	const int size = p-p0;

	for (auto i = 0; i != size; ++i)
		cout << p0[i] << " ";                 // P0可看作数组
	cout << endl;

	while (p != p0) {

		a.destroy(--p);
	}
	a.deallocate(p, n);
	cout << size << endl;



}