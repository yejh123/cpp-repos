#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	string s1 = "ads",s2;
	istringstream ist;
	ostringstream ost;
	
	ist .str("kjh");         //����ʹ��ist>>"kjh"
	ist >> s2;
	cout << s2 <<  endl;
	ost << s1 << endl;       //��ostд�����ݣ�ost����������з�.
	cout << "�м�" << endl;
	cout << ost.str() ;
	return 0;
}