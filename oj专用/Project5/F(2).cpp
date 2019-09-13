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
bool better(int i1, int i2) {
	vector<int> a1, a2;
	intToVector(a1, i1);

	intToVector(a2, i2);
//comparator需要时strict weak ordering，需要注意的是，comparator(x,x)必须返回false。
	for (int i = 0; i < a1.size() || i < a2.size(); ++i) {
		if (a1[i] > a2[i])
			return true;
		if (a2[i] > a1[i])
			return false;
		if (i == a1.size() - 1 && i < a2.size() - 1) {			//a2长
			int t1 , t2;
			for (t1 = 0, t2 = 0; t2 < a2.size() - i; ++t1, ++t2) {
				if (t1 == a1.size())
					t1 -= a1.size();
				if (a2[i + t2] > a1[t1])
					return false;
				if (a2[i + t2] < a1[t1])
					return true;
			}
			if (a2[i + t2 - 1] > a1[0])
				return false;
			else return true;
		}
		if (i == a2.size() - 1 && i < a1.size() - 1) {				//a1长
			int t1, t2;
			for (t1 = 0, t2 = 0; t1 < a1.size() - i; ++t1, ++t2) {		
				if (t2 == a2.size())
					t2 -= a2.size();
				if (a1[i + t1] > a2[t2])
					return true;
				if (a1[i + t1] < a2[t2])
					return false;
			}
			if (a1[i + t1 -1] > a2[0])
				return true;
			else return false;
		}
	}
	return false;
}
int main() {
	vector<int> a;
	intToVector(a, 456);

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