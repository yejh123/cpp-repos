#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm> //Ö§³Ösout,unique
using namespace std;
void f(vector<string> &vs) {
	sort(vs.begin(), vs.end());
	for (auto a : vs)
		cout << a << " ";
	cout << vs.size();
	cout << endl;
	auto it = unique(vs.begin(), vs.end());
	for (auto a : vs)
		cout << a << " ";
	cout << vs.size();
	cout << endl;
	vs.erase(it, vs.end());
	for (auto a : vs)
		cout << a << " ";
	cout << vs.size();
}
int main() {
	vector<string> vs{"money", "how", "fuck", "mother", "good", "bitch", "suck", "dick", "man", "holy","how","fuck","good"};
	f(vs);
	
}