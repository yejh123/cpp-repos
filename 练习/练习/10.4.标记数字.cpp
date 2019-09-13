#include <iostream>
#include <string>
using namespace std;
//int main() {
//	string str;
//	cin >> str;
//	regex pattern("(\\.)*(\\d+)(\\.)*");
//	string s = regex_replace(str, pattern, "$1*$2*$3");
//	cout << s;
//}
int main() {
	string s;
	cin >> s;
	bool flag = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (flag == 0 && s[i] >= '0' && s[i] <= '9') {
			cout << '*' << s[i];
			flag = 1;
		}
		else if(flag ==1 && !(s[i] >= '0' && s[i] <= '9')){
			cout<<'*'<<s[i];
			flag = 0;
		}
		else {
			cout << s[i];
		}

	}
	if (flag)
		cout << '*';
	cout << endl;
}