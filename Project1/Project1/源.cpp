#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int c1, c2;
	c1 = cin.get();
	c2 = cin.get();
	cout << c1 << " " << c2 << endl; // ��ӡ�����ַ�
	cout << (int)c1 << " " << (int)c2 << endl; // ��ӡ�������ַ���ASCIIֵ

	cin >> c1;
	cin >> c2;
	cout << c1 << " " << c2 << endl; // ��ӡ�����ַ�
	cout << (int)c1 << " " << (int)c2 << endl;
	return 0;

}
/*
int main()
{
	int a, b = 1;
	while (cin >> a) {
		cout << "��" << b << "��:" << endl;
		cout << "cin.failbit:"<<cin.fail() << endl;
		cout << "cin.eofbit:"<<cin.eof() << endl;
		cout << "cin.badbit:"<<cin.bad() << endl;
		cout << "cin.goodbit"<<cin.good() << endl;
		cout << cin.rdstate() << endl;
		cout << endl;
		++b;
		cin.clear();
	}
	cout << "��" << b << "��:" << endl;
	cout << cin.eof() << endl;
	cout << cin.fail() << endl;
	cout << cin.bad() << endl;
	cout << cin.good() << endl;
	cout << cin.rdstate() << endl;
	cout << endl;
	++b;
}

*/