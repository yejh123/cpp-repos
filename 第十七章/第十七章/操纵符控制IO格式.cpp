/*
(1)dec:设置整数基数为10，用于输出和输入；

(2)hex:设置整数基数为16，用于输出和输入；

(3)oct:设置整数基数为8，用于输出和输入；

(4)ws:跳过输入的空格符，用于输入；

(5)endl:输出一个换行符并刷新输出流，用于输出；

(6)ends:插入一个空字符null，通常用来结束一个字符串，用于输出；

(7)flush:刷新一个输出流，用于输出；

(8)setbase(n):设置整数的基数为n(可取0或10代表十进制，8代表八进制和16代表十六进制，默认为0)，用于输入和输出；

(9)setfill©:设置填充符(默认为空格)，用于输出；

(10)setprecision(n):设置实数精度n,原理和成员函数precision一样，用于输出；

(11)setw(n):设置域宽n，用于输出；

(12)setiosflags(flags):设置指定状态标志，多个用"|"分隔，用于输出和输入；

(13)resetiosflags(flags):清除指定状态标志，多个用"|"分隔，用于输出和输入；
*/
#include<iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {

	cout << boolalpha << true << " " << false << endl;
	cout << noboolalpha << true << " " << false << endl;
	cout << showbase << uppercase << 1024 << " " << oct << 1024 << " " << hex << 1024 << " " << dec << 1024 << endl;
	cout << hexfloat << 100 * sqrt(2.0) << defaultfloat << endl;;
	cout << showpoint << (double)16 << endl;
	cout << showpos << 16 << noshowpos<<endl;
	//cout << setprecision(3) << 3.1 << endl;
	cout << double(5) << endl;

	cout << fixed  << 3.1 << endl;
	cout << setprecision(3) << 3.1 << endl;
	cout << resetiosflags(ios::fixed) << 3.1 << endl;
	cout << setprecision(6)<<double(5) << endl;				//恢复默认精度6
	cout << scientific << setprecision(3) << 3.1 << endl;
	cout << 3.1 << endl;
	cout << setfill('\t')<<setw(10) << "a" << endl;			//setw(n)只对下一个输出有效
	cout << "a" << endl;
}