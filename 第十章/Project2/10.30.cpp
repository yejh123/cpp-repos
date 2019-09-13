#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;
int main()
{
	
	istream_iterator<int> its(cin), eof;
	vector<int> vi;
	auto it = back_inserter(vi);
	copy(its, eof, it);
	sort(vi.begin(), vi.end());
	ostream_iterator<int> oti(cout," ");
	unique_copy(vi.cbegin(), vi.cend(),  oti);
	cout << endl;
	
	/*
	for (auto a : vi)
		oti = a;
	cout << endl;
	*/
	
}