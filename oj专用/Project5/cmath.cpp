#include <iostream>
using namespace std;
int fact(int val)
{
	static int a = 0;
	++a;
	cout <<"该函数已被调用"<< a<<"次"<<endl;
	if (val < 0)
		return -val;
	else return val;

}
int main()
{
	int a = 2, b = 1;
	double c = log(1 + pow(abs((a + b) / (a - b)), 10));
	double d = log1p(pow(abs((a + b) / (a - b)), 10));
	cout << c << endl << d;
	//double d = cot()
		return 0;

}