#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Sales_data.h"
using namespace std;
bool compareIsbn(const Sales_data &s1, const Sales_data &s2) {
	return s1.isbn() < s2.isbn();
}
void salesSort(vector<Sales_data> &vs) {
	

	sort(vs.begin(), vs.end(),compareIsbn);
	


}
int main() {
	ifstream in("data");
	vector<Sales_data> vs;
	Sales_data s;
	
	
	while (read(in, s),in)
	{
		vs.push_back(s);
	}
	salesSort(vs);
	for (auto a : vs)
		print(cout, a);
		
}