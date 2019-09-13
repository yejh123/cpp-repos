#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	vector<string> vs{ "dasf","ajsasafdg","fajo","jha","hjaf9hp","sthadqsd","ajs","fihaos", "jha","dasho","dhas","fajo","dhsihoihf" };
	auto i = count_if(vs.begin(), vs.end(), [](const string &s) {return s.size() > 6; });
	cout << i << endl;
}