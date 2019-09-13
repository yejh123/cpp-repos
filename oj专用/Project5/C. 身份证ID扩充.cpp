#include<iostream>
#include<string>
using namespace std;
/*仅提交以下代码*/
//7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2
class ID {
	// 在此处补充你的代码
public:
	string s;
	string newID;

	ID(string s) {
		this->s = s;
	}
	void change() {
		s.resize(18);
		for (int i = 16; i >= 8; --i) {
			s[i] = s[i - 2];
		}
		s[6] = '1';
		s[7] = '9';
		int a[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
		int sum = 0;
		for (int i = 0; i < 17; ++i) {
			sum += a[i] * (s[i] - 48);
		}
		char c[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
		s[17] = c[sum % 11];
		newID = s;
	}
};
/*仅提交以上代码*/
int main()
{
	string str;
	while (cin >> str) {
		ID myID(str);
		myID.change();
		cout << myID.newID << endl;
	}
	return 0;
}