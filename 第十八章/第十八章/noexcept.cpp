#include "test.h"
int main()
{
	int a;
	cin >> a;
	try {
		if (a == 0)
			throw runtime_error("0���ܵ�����");
		cout << (1000 / a) << endl;

	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}