#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1, s2, s3;
//	ungetºÍputback
//	cin >> s1;
//	cin.putback('c')>>s2;
//	cin >> s3;
//	cout << s1 << " " << s2 << " " << s3 << endl;
	signed char c = '\376';
	cout << bool(c == EOF) << endl;
	//is.get(sink, size, delim);
	/*char *c = new char[10];
	cin.getline(c, 5);
	cout << cin.gcount()<<" "<<c << endl;
	cin.get(c, 10);
	cout << cin.gcount() << " "<<c << endl;
	cout.write(c, 5);*/

}