#include "String.h"
#include <vector>
int main() {
	vector<String> vs; //无输出
	cout << endl;
	String s("dsa");   //C风格
	cout << endl;
	String s1 (s);     //拷贝构造函数
	cout << endl;
	vs.push_back("chang"); //调用C风格字符串初始化创建临时对象,再调用拷贝构造函数(移动构造函数,且如果定义了移动构造函数，优先使用移动构造函数)

	cout << endl;
	vs.push_back(s1);      //调用拷贝
	cout << endl;
	vs.push_back(s1);      //拷贝
	cout << endl;
	vs.push_back(String("fji"));           //C风格
	cout << endl;
	vs.push_back(std::move("dhauo"));      //C风格
}