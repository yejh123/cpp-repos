#include <iostream>
#include <string>
using namespace std;
int i;
istream& f(istream& is)
{
	
	while (is >> i , !is.eof())//P.S.���Ų����滻��&& ��C++pimer P140
	{
		cout << is.fail() << " " << is.eof() << endl;
		if (is.fail()) {
			cout << is.fail() << endl;
			cerr << "�������,����������" << endl;
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