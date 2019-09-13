#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	string s1 = "ads",s2;
	istringstream ist;
	ostringstream ost;
	
	ist .str("kjh");         //不能使用ist>>"kjh"
	ist >> s2;
	cout << s2 <<  endl;
	ost << s1 << endl;       //向ost写入数据，ost对象包含换行符.
	cout << "中间" << endl;
	cout << ost.str() ;
	return 0;
}