#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int v1[1] { 1 };
	string v2[1] { "hello" };
	auto *p1 = begin(v1);
	auto *p2 = begin(v2);

	p1 += p2 - p1;
	cout << p1 << endl;
	cout << *p1<<" " <<*p2 << endl;
}