#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string s;
istream& f(istream& is)
{
	string v;
	while (is>>v, !is.eof())//P.S.逗号不能替换成&& 见C++pimer P140
	{
		
		//cout << is.fail() << " " << is.eof() << endl;
		if (is.fail()) {
			cout << is.fail() << endl;
			cerr << "输入错误,请重新输入" << endl;
			is.clear();
			is.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	//cout << is.fail() << " " << is.eof() << endl;
	is.clear();
	//cout << is.fail() << " " << is.eof() << endl;
	return is;
}
int main()
{
	ostringstream msg;
	msg << "sb chang shi sb" << endl;
	//istringstream in("sb chang shi sb a"); //当is读取到a时，触发"文件结束"信号，即is.eof()返回1，导致a不会被输出，将"sb chang shi sb a"换成msg可解决该问题.
	cout << msg.str() << endl;
	istringstream in(msg.str());
	f(in);
	return 0;
}
