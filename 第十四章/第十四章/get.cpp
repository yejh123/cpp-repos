#include<iostream>
using namespace std;
int main()
{
	char input[5], s[6];
	/*for (int i = 0; i < 5; ++i)
	{
		cin.get(input[i]);
		cout << input[i];
	}*/

	//cin.get(input, 6);      //数组的最后一个字符会是‘\0’，设接收字符数目为n，
	                        //如果输入的字符串大于等于n，则实际接收到的输入是字符串的前面n-1个字符，
	                        //包括空格（不包括回车，遇到回车就结束了），会自动在后面增加一个‘\0’。
	//cout << input;  

	cin.get(input, 5);
	cin.get(input, 5);          //get（）函数不再读取并丢弃换行符，二是将换行符保存到队列中
	//cin.get(s,6);
	cin.get();                  //若输入的字符少于5个，cin.get()无法舍弃换行符
	cin.get(s, 6);
	cout << input << " " << s << endl;
}