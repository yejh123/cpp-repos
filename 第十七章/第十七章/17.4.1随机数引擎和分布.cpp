#include<iostream>
#include <random>

using namespace std;
unsigned int myRand()
{
	static default_random_engine e(-1);
	uniform_int_distribution<unsigned> u(0, 99);
	return u(e);
}
int main()
{
	default_random_engine e1;
	cout << "min:" << e1.min() << ", max:" <<  e1.max() << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << myRand() << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << myRand() << " ";
	}

}