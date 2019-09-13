#include "Chapter10.h"
void for_each_test() {
	vector<int> vec = { 59,29,9,9649,599 ,2982 };
	for_each(vec.cbegin(), vec.cend(), [](int i) {cout << i << " "; });
	cout << endl;
}