#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int i1;
	cin >> i1;
	auto f = [i1](int i2) {return i1 + i2; };
	cout << f(12) << endl;
	
}
