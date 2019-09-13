#include <iostream>
using namespace std;

int main()
{

	int   input;
	while (cin >> input)
	{
		cout << input << endl;
		cout << "rdstate()函数的返回值： " << cin.rdstate() << endl;
		cout << "三个标记位返回的返回值： " << cin.fail() << cin.bad() << cin.eof() << endl;
		cout << "goodbit标记位的返回值： " << cin.good() << endl;
		cout << endl;
	}

	cout << "rdstate()函数的返回值： " << cin.rdstate() << endl;
	cout << "三个标记位返回的返回值： " << cin.fail() << cin.bad() << cin.eof() << endl;
	cout << "goodbit标记位的返回值： " << cin.good() << endl;

	if (!cin)
		cout << "input error" << endl;

	else
		cout << input << endl;



	
	return 0;
}