#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int i = 5;

	auto f = [&i]()mutable->bool {
		
		if (i > 0) {
			--i;

			return 1;
		}
		else return 0;
	};
	while (f())
		cout << i << " ";
	cout<<f();
}