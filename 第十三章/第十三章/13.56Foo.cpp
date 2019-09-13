#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Foo.h"
using namespace std;
int main()
{
	vector<int> vi{ 465,8,56,5,566 };
	Foo f(vi);
	auto f1 = f.sorted();
	f.print();
	f1.print();
	f.sorted().sorted();
}