#include <iostream>
using namespace std;
int main() {
	cout.setf(ios::left);
	int a = 982;
	cout.width(10);
	cout << "start:";
	cout.setf(ios::hex, ios::basefield);		//�ȸ�λ����λ������ʮ�������
	cout.width(10);
	cout << a;
	cout.setf(ios::oct, ios::basefield);		//�ȸ�λ����λ������ʮ���������
	cout.width(10);
	cout << a;
}