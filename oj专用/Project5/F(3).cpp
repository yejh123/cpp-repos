#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void intToVector(vector<int>& vec, int i) {
	if (i / 10 != 0) {
		intToVector(vec, i / 10);
	}
	vec.push_back(i % 10);
}
static bool better(int a, int b) {
	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(b) + to_string(a);
	return (s1.compare(s2) > 0);
}
int main() {
	int n;
	while (cin >> n) {
		if (n == -1)
			return 0;
		vector<int> vec;
		int i;
		for (int t = 0; t < n; ++t) {
			cin >> i;
			vec.push_back(i);
		}
		sort(vec.begin(), vec.end(), better);
		for (int t = 0; t < n; ++t) {
			cout << vec[t];
		}
		cout << endl;
	}
}