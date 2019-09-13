#include<iostream>
#include <string>
using namespace std;

/***** 仅提交以下代码 *****/
class CHugeInt {
	// 在此处补充你的代码
	char c[210];
	//bool flag;
public:
	CHugeInt(char s[]){
		strcpy_s(c, s);
	}
	CHugeInt(int i)  {
		int n = 0;
		int i2 = i;
		while (i2) {
			++n;
			i2 = i2 / 10;
		}
		while (i) {
			c[n] = '\0';
			c[n-- - 1] = char(i % 10 + 48);
			i /= 10;
		}
	}
	char *operator+(const CHugeInt& right) const{
		char a[210];
		int size1 = size(this->c);
		int size2 = size(right.c);
		int longer;
		int shorter;
		char c1[210];
		char c2[210];
		if (size1 > size2) {
			strcpy_s(c1, this->c);
			strcpy_s(c2, right.c);
			longer = size1;
			shorter = size2;
			strcpy_s(a, c1);
		}
		else {
			strcpy_s(c1, right.c);
			strcpy_s(c2, this->c);
			longer = size2;
			shorter = size1;
			strcpy_s(a, c2);
		}
		bool flag = 0;
		for (int i = 1; i <= longer; ++i) {
			if (i <= shorter) {
				a[longer - 1] += c2[shorter - 1] + flag - 48;
				flag = 0;
				if (a[longer - 1] >= 58) {
					a[longer - 1] -= 10;
					flag = 1;
				}
			}
			else {
				a[longer - 1] +=  + flag - 48;
				flag = 0;
				if (a[longer - 1] >= 58) {
					a[longer - 1] -= 10;
					flag = 1;
				}
			}
			
		}
		return a;
	}
};
/***** 仅提交以上代码 *****/

int main()
{
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);
		cout << a + b << endl;
		//cout << n + a << endl;
		//cout << a + n << endl;
	}
	return 0;
}