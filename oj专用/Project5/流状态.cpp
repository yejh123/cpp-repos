#include <iostream>
using namespace std;

int main()
{

	int   input;
	while (cin >> input)
	{
		cout << input << endl;
		cout << "rdstate()�����ķ���ֵ�� " << cin.rdstate() << endl;
		cout << "�������λ���صķ���ֵ�� " << cin.fail() << cin.bad() << cin.eof() << endl;
		cout << "goodbit���λ�ķ���ֵ�� " << cin.good() << endl;
		cout << endl;
	}

	cout << "rdstate()�����ķ���ֵ�� " << cin.rdstate() << endl;
	cout << "�������λ���صķ���ֵ�� " << cin.fail() << cin.bad() << cin.eof() << endl;
	cout << "goodbit���λ�ķ���ֵ�� " << cin.good() << endl;

	if (!cin)
		cout << "input error" << endl;

	else
		cout << input << endl;



	
	return 0;
}