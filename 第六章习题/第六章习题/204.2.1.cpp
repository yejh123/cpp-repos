#include<iostream>
using namespace std;
ostream &binary(unsigned i);
void swap1(double &a, double &b);
int main()
{
	unsigned i = 511;
	double a = 123.456, b = 456.789;
	swap1(a, b);
	cout << a << " " << b << endl;
}
ostream &binary(unsigned i)
{
	unsigned t = 1<<31;
	for (int a = 0; a <= 31; ++a)
	{
		cout << (t >> a & i? '1':'0');
	}
	cout << endl;
	return cout;
}
void swap1(double &a, double &b)
{
	int *ap, *bp;
	ap = (int *)(&a);
	bp = (int *)(&b);
	*ap = (*ap) ^ (*bp);
	*bp = (*ap) ^ (*bp);
	*ap = (*ap) ^ (*bp);
	ap++, bp++;
	*ap = (*ap) ^ (*bp);
	*bp = (*ap) ^ (*bp);
	*ap = (*ap) ^ (*bp);
}