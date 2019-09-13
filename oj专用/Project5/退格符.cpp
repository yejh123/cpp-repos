#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
int main()
{
	cout << 'd' << 'a' << 'f' << '\b' << '\b' <<'c'<< '\n' << "fauck" << 'd' << '\b' ;
	cout << '\n';
    cout << '\b' << "fauck" << endl;
	/*
	int a, b;
	while (cin >> a >> b) {
		try {


			if (b == 0)
				throw runtime_error("除数不能为0");
			cout << a / b << endl;
			return 0;

		}
		catch (runtime_error err) {
			cout << err.what() << endl;
			cout << "需要继续吗" << endl;
			char ch;
			cin >> ch;
			
			if (ch != 'y' &&ch != 'Y')
				break;
			else cout << "请输入两个数" << endl;
		}
	}
	return 0;
	*/
}