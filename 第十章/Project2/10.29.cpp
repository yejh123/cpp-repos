#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;
int main()
{
	ifstream in("data");
	istream_iterator<string> its(in),eof;
	vector<string> vs(its, eof);
	for_each(vs.cbegin(), vs.cend(), [](const string &s) {cout << s << endl; });


}