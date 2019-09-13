#include <iostream> 
using namespace std;
/*
当cin.rdstate()返回0(即ios::goodbit)时表示无错误, 可以继续输入或者操作
若返回4则发生非致命错误即ios::failbit, 则不能继续输入或操作.而cin.clear则可以控制我们此时cin里对这个问题的一个标识.语法如下:
cin.clear(标识符);
标识符号为:
goodbit 无错误 0
Eofbit 已到达文件尾 1
failbit 非致命的输入 / 输出错误，可挽回 2
badbit　致命的输入 / 输出错误, 无法挽回 3
*/
int main()
{
	int a;
	cout << ios::goodbit << " " << ios::failbit << " " << ios::badbit << " " << ios::eofbit << endl;
	while (1)
	{
		cin >> a;
		cout << "cin.rdstate():" << cin.rdstate() << endl;
		if (cin.fail())            //条件可改写为cin.fail() 
		{
			cout << "输入有错!请重新输入" << endl;
			cin.clear(ios::goodbit);
			cin.ignore();   //清空流
		}
		else
		{
			cout << a;
			break;
		}
	}
	system("pause");
}