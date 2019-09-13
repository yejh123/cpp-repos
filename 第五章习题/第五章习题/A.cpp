#include<iostream>
#include<iomanip>
using namespace std;
struct C
{
	double a;
	double b;
};
int main()
{
	C c1, c2;
	while (cin>>c1.a>>c1.b>>c2.a>>c2.b)
	{
		char c;
		cin >> c;
		switch (c)
		{
			case '+':
			cout << fixed << setprecision(4) << c1.a + c2.a << " " << c1.b + c2.b << endl;
			break;
			case '-':
				cout << fixed << setprecision(4) << c1.a - c2.a << " " << c1.b - c2.b << endl;
				break;
		}
	}
}