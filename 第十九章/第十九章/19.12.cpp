#include <iostream>
#include <string>
using namespace std;
class Screen {
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(string str) :contents(str) {}

	string contents;
	pos cursor;
	pos hright, width;
};
int main() {
	Screen myScreen("dajsodboa"), *pScreen = &myScreen;
	const string Screen::*pdata = &Screen::contents;		//定义数据成员指针
	string s = myScreen.*pdata;
	cout << s << endl;
	const Screen::pos Screen::*pCursor = &Screen::cursor;
	cout << pScreen->*pCursor << endl;
}