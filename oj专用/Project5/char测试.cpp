#include <iostream>
#include <string>
using namespace std;

int main()
{
	char c[30] = "fuck";
	cout << strlen(c) << endl;
	strcpy_s(c, 8 ,"asdoin");           // strlen(c)Ӧ����strlen("asdoin") �ҵڶ����β�Ҫ����strlen("asdoin")
	cout << strlen(c) << endl;          // strlen(c) �� 4 -> 6


}