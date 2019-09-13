#include <iostream>
using namespace std;
void query()
{
	int *p;
	p = new int[3];
	delete[]p;
	p = new double[5];
	delete[]p;
}
int main()
{

}