#include "Chapter10.h"
void partition_test() {
	vector<int> vec= { 16,99,29,85,1,4848,8,48,35,656 };
	partition(vec.begin(), vec.end(), [](int i)->bool {return i < 50; });			//partition只接受一元谓词
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
}