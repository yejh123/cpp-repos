#include <iostream>
#include <vector>
using namespace std;
extern template class vector<int>;
int main() {
	vector<int> v = { 1,2,3 };
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
}