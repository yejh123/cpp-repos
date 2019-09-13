#include "Only-readAlgorithm.h"
void replace_copy_test() {
	vector<int> vec1 = { 1,2,5,3,5 };
	vector<int> vec2;
	replace_copy(vec1.cbegin(), vec1.cend(), back_inserter(vec2), 5, 4);
	for (auto i : vec2) {
		cout << i << " ";
	}
	cout << endl;
}