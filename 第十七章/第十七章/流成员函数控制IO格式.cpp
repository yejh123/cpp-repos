#include <iostream>
using namespace std;
int main() {
	cout.setf(ios::left);
	int a = 982;
	cout.width(10);
	cout << "start:";
	cout.setf(ios::hex, ios::basefield);		//先复位再置位，否则按十进制输出
	cout.width(10);
	cout << a;
	cout.setf(ios::oct, ios::basefield);		//先复位再置位，否则按十六进制输出
	cout.width(10);
	cout << a;
}