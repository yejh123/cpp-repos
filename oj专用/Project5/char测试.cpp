#include <iostream>
#include <string>
using namespace std;

int main()
{
	char c[30] = "fuck";
	cout << strlen(c) << endl;
	strcpy_s(c, 8 ,"asdoin");           // strlen(c)应大于strlen("asdoin") 且第二个形参要大于strlen("asdoin")
	cout << strlen(c) << endl;          // strlen(c) 从 4 -> 6


}