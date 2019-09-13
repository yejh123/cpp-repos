#include <iostream>
using namespace std;
int main()
{
	const int i1 = 6;
	int i2 = static_cast<int>(i1);
	cout << i1 << " " << i2 << endl;
	i2 = 5;
	cout << i1<<" "<<i2 << endl;
}