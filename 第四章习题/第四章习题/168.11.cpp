#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void pack(int *pi, unsigned char * &pc, int n);
void unpack(int * &pi2, unsigned char *pc, int n);
int main()
{

	int n;
	cin >> n;
	int *pi = new int[n], *pi2;
	unsigned char *pc;
	srand(int(time(0)));
	for (int i = 0; i < n; ++i)
	{
		pi[i] = rand() % 256;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << pi[i] << " ";
	}
	cout << endl;
	pack(pi, pc, n);
	for (int i = 0; i < n; ++i)
	{
		cout << (int)pc[i] << " ";
	}
	cout << endl;
	unpack(pi2, pc, n);
	for (int i = 0; i < n; ++i)
	{
		cout << pi2[i] << " ";
	}
	cout << endl;
	
}
void pack(int *pi, unsigned char * &pc, int n)
{
	pc = new unsigned char[n];
	for (int i = 0; i < n; ++i)
	{
		pc[i] = (unsigned char)pi[i];
	}
}
void unpack(int * &pi2, unsigned char *pc, int n)
{
	pi2 = new int[n];
	for (int i = 0; i < n; ++i)
	{
		pi2[i] = pc[i];
	}
}