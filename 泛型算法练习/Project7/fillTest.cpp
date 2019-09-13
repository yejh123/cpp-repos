#include "Chapter10.h"
void fillTest() {
	vector<int> vec(10);
	fill(vec.begin(), vec.end(), 42);
	for (size_t i : vec) {
		cout << i << " ";
	}
	cout << endl;
}
void fill_n_test() {
	vector<int> vec(10);
	fill_n(vec.begin(), vec.size(), 43);
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
}
void back_inserter_test() {
	vector<int> vec;
	auto it = back_inserter(vec);
	fill_n(it, 10, 44);
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
}