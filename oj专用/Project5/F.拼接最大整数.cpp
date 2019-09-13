#include <iostream>
#include <string>
#include <vector>
using namespace std;
int get(int n, int i) {
	while (n >= pow (10,i)) {
		n /= 10;
	}
	return n % 10;
}
int match(vector<int> vec, int n) {
	if (n > 1) {
		for (auto it = vec.begin(); it < vec.end();) {
			if (vec.size() == 1) {
				cout << vec[0];
				return vec[0];
			}

			if (get(*it, n) == 0) {
				cout << "删除的数:" << *it << endl;
				it = vec.erase(it);
				continue;
			}
			else {
				++it;
			}
			if (*it < pow(10, n - 1)) {
				it = vec.erase(it);
			}
			else {
				++it;
			}
		}
	}
	if (vec.size() == 1) {
		cout << vec[0];
		return vec[0];
	}
	vector<int> index;
	int max = 0;
	for (int i = 0; i < vec.size(); ++i) {
		int temp = vec[i];
		temp = get(temp, n);			//得到从左往右第n位数
		if (temp > max) {
			max = temp;
		}
	}
	for (int i = 0; i < vec.size(); ++i) {
		int temp = vec[i];
		temp = get(temp, n);			//得到从左往右第n位数
		if (temp == max) {
			index.push_back(vec[i]);
			cout << "添加的数" << vec[i] << endl;
		}
	}
	if (index.size() == 1)
		return index[0];
	else {
		return match(index, n + 1);
	}

}
string maxMatch(vector<int> vec) {
	string s;
	while (!vec.empty()) {
		int max = match(vec, 1);
		s += to_string(max);
		cout << "max in main:" << max << endl;
		auto it = find(vec.cbegin(), vec.cend(), max);
		vec.erase(it);
	}
	return s;
}
int main() {
	vector<int> is = { 1,2,3,4 };
	is.erase(is.begin());
	cout << is[0] << endl;
	int size;
	while (cin >> size) {
		vector<int> vec;
		if (size == -1)
			return 0;
		for (int i = 0; i < size; ++i) {
			int t;
			cin >> t;
			vec.push_back(t);
		}
		cout << maxMatch(vec) << endl;
	}
}