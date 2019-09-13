#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct NoSame {
	bool operator()(int i1 ,int i2 = 11)
	{
		return i1 == i2;
	}
 };
int main() {
	vector<int> vi{ 4654,5165,14,12,21,52,133,11,566515,4,64,22,11 };
	NoSame ns;
	replace_if(vi.begin(), vi.end(), ns, 0);
	for (auto a : vi)
		cout << a << " ";
	cout << endl;
}