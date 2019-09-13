#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	auto f = [](int i1, int i2) {
		return i1 + i2;
	};
	cout << f(1, 2) << endl;
}