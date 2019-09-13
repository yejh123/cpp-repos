#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int c1, c2;
	c1 = cin.get();
	c2 = cin.get();
	cout << c1 << " " << c2 << endl; // 打印两个字符
	cout << (int)c1 << " " << (int)c2 << endl; // 打印这两个字符的ASCII值

	cin >> c1;
	cin >> c2;
	cout << c1 << " " << c2 << endl; // 打印两个字符
	cout << (int)c1 << " " << (int)c2 << endl;
	return 0;

}
/*
int main()
{
	int a, b = 1;
	while (cin >> a) {
		cout << "第" << b << "次:" << endl;
		cout << "cin.failbit:"<<cin.fail() << endl;
		cout << "cin.eofbit:"<<cin.eof() << endl;
		cout << "cin.badbit:"<<cin.bad() << endl;
		cout << "cin.goodbit"<<cin.good() << endl;
		cout << cin.rdstate() << endl;
		cout << endl;
		++b;
		cin.clear();
	}
	cout << "第" << b << "次:" << endl;
	cout << cin.eof() << endl;
	cout << cin.fail() << endl;
	cout << cin.bad() << endl;
	cout << cin.good() << endl;
	cout << cin.rdstate() << endl;
	cout << endl;
	++b;
}

*/