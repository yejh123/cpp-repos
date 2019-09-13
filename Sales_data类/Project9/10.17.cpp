#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Sales_data.h"
using namespace std;

void salesSort(vector<Sales_data> &vs) {
	sort(vs.begin(), vs.end(), [](Sales_data  s1, Sales_data s2) {return s1.isbn() < s2.isbn(); });

}
int main() {
	ifstream in("data");
	vector<Sales_data> vs;
	Sales_data s;


	while (read(in, s), in)
	{
		vs.push_back(s);
	}
	salesSort(vs);
	for (auto a : vs)
		print(cout, a);

}