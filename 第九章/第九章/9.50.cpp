#include <iostream>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	vector<string> v{"132.12","73.51","24.12","782.97","4.20","42.45","432.38" };
	double total = 0;
	for (auto a : v) {
		total += stod(a,0);
	}
	cout << total;
}