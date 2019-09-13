#include <iostream>
#include <string>
#include <deque>
#include <list>
using namespace std;
int main()
{
	list<int> l{ 12,4,5,55,45,8,54,548,7,54,54,44 ,485,41,4,44,6,46,4564,6,4,4,54,9};
	deque<int> de1, de2;
	auto it = l.cbegin();
	for (; it != l.cend(); ++it) {
		if ((*it) % 2 == 1)
			de1.push_back(*it);
		else de2.push_back(*it);
	}
	cout << "de1:";
	for (auto a : de1)
		cout << a << " ";
	cout << endl;
	cout << "de2:";
	for (auto a : de2)
		cout << a << " ";
	cout << endl;
}