#include <iostream>
#include <string>
using namespace std;
int i;
istream& f(istream& is)
{
	
	while (is >> i , !is.eof())//P.S.逗号不能替换成&& 见C++pimer P140
	{
		cout << is.fail() << " " << is.eof() << endl;
		if (is.fail()) {
			cout << is.fail() << endl;
			cerr << "输入错误,请重新输入" << endl;
			is.clear();
			is.ignore(100, '\n');
			continue;
		}
		cout << i << endl;
	}
	cout << is.fail() << " " << is.eof() << endl;
	is.clear();
	cout << is.fail() << " " << is.eof() << endl;
	return is;
}
int main() {
	f(cin);
	return 0;
}