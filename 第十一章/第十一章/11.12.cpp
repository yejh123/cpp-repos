#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<pair<string, int>> vp;
	vector<string> vs{ "fuck","your","mother" };
	vector<int> vi{ 1,2,3 };
	pair<string, int> p;
	unsigned i = 0;
	for (vector<string>::const_iterator it = vs.cbegin(); it != vs.cend(); ++it) {
		vp.push_back({ *it,vi[i++] });
		//vp.push_back( pair<string,int>(*it,vi[i++] ) );
		//vp.push_back(make_pair(*it, vi[i++]) );
	}
	for (auto a : vp) {
		cout << a.first << " " << a.second << endl;
	}
}