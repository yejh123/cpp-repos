#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
bool f(vector<int> &vi, int i) {
	modulus<int> md;
	return count_if(vi.begin(), vi.end(), bind1st(md, i)) == 0;    //count接受一元谓词
}
int main() {
	vector<int> vi{ 1,2,4 ,5};
	auto bl = f(vi, 16);
	cout << bl << endl;
}