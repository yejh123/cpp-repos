#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int ia2[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };

	for (int (*a)[4] = ia2; a!= end(ia2); ++a)
	{
		for (int *b = *a; b != *a+4; ++b)
			cout << *b << " ";
		cout << endl;
	}
	return 0;
}