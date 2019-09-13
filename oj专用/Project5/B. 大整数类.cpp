#include <iostream>
#include <string>
using namespace std;

/***** 仅提交以下代码 *****/
class CHugeInt {
	// 在此处补充你的代码
	string s;
public:
	friend string operator+(int n, const CHugeInt& c2);
	CHugeInt(char *c) {
		s = c;
	}
	CHugeInt(int i) {
		s = to_string(i);
	}
	string operator+(const CHugeInt& c) {
		string res;
		int size1, size2;
		string s2;
		if (this->s.size() > c.s.size()) {
			size1 = this->s.size();
			size2 = c.s.size();
			res = this->s;
			s2 = c.s;
		}
		else {
			size1 =  c.s.size();
			size2 = this->s.size();
			res = c.s;
			s2 = this->s;
		}
		bool flag = 0;
		for (int i = 1; i <= size1; ++i) {
			if (i <= size2) {
				res[size1 - i] += s2[size2 - i] + flag - 48;
				flag = 0;
				if (res[size1 - i] >= 58) {
					flag = 1;
					res[size1 - i] -= 10;
				}
			}
			else {
				if (flag == 0)
					break;
				res[size1 - i] +=  flag ;
				flag = 0;
				if (res[size1 - i] >= 58) {
					flag = 1;
					res[size1 - i] -= 10;
				}
			}
			//cout << res[size1 - i];
		}
		if (flag) {
				res = "1" + res;
		}
		return res;
	}
	string operator+(int n) {
		CHugeInt c(n);
		string res;
		int size1, size2;
		string s2;
		if (this->s.size() > c.s.size()) {
			size1 = this->s.size();
			size2 = c.s.size();
			res = this->s;
			s2 = c.s;
		}
		else {
			size1 = c.s.size();
			size2 = this->s.size();
			res = c.s;
			s2 = this->s;
		}
		bool flag = 0;
		for (int i = 1; i <= size1; ++i) {
			if (i <= size2) {
				res[size1 - i] += s2[size2 - i] + flag - 48;
				flag = 0;
				if (res[size1 - i] >= 58) {
					flag = 1;
					res[size1 - i] -= 10;
				}
			}
			else {
				if (flag == 0)
					break;
				res[size1 - i] += flag;
				flag = 0;
				if (res[size1 - i] >= 58) {
					flag = 1;
					res[size1 - i] -= 10;
				}
			}
			//cout << res[size1 - i];
		}
		if (flag) {
			res = "1" + res;
		}
		return res;
	}
};
string operator+(int n, const CHugeInt& c2) {
	CHugeInt c1(n);
	string res;
	int size1, size2;
	string s2;
	if (c1.s.size() > c2.s.size()) {
		size1 = c1.s.size();
		size2 = c2.s.size();
		res = c1.s;
		s2 = c2.s;
	}
	else {
		size1 = c2.s.size();
		size2 = c1.s.size();
		res = c2.s;
		s2 = c1.s;
	}
	bool flag = 0;
	for (int i = 1; i <= size1; ++i) {
		if (i <= size2) {
			res[size1 - i] += s2[size2 - i] + flag - 48;
			flag = 0;
			if (res[size1 - i] >= 58) {
				flag = 1;
				res[size1 - i] -= 10;
			}
		}
		else {
			if (flag == 0)
				break;
			res[size1 - i] += flag;
			flag = 0;
			if (res[size1 - i] >= 58) {
				flag = 1;
				res[size1 - i] -= 10;
			}
		}
		//cout << res[size1 - i];
	}
	if (flag) {
		res = "1" + res;
	}
	return res;
}
/***** 仅提交以上代码 *****/

int main()
{
	char s[210];
	int n;
	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);
		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
	}
	return 0;
}