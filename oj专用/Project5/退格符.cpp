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
				throw runtime_error("��������Ϊ0");
			cout << a / b << endl;
			return 0;

		}
		catch (runtime_error err) {
			cout << err.what() << endl;
			cout << "��Ҫ������" << endl;
			char ch;
			cin >> ch;
			
			if (ch != 'y' &&ch != 'Y')
				break;
			else cout << "������������" << endl;
		}
	}
	return 0;
	*/
}