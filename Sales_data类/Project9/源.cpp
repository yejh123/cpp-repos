#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;
int main()
{
	//Sales_data s2;
	cout << "������s1��bookNo��units_sold��revenue" << endl;
	Sales_data s1;
	//cin >> s1.bookNo >> s1.units_sold >> s1.revenue;
	//read(cin, s1);
	cout << "s1��bookNo��units_sold��revenue�ֱ�Ϊ:";
		print(cout,s1) ;
	/*cout << "������s2��bookNo��units_sold��revenue" << endl;
	cin.clear();
	cin >> s2.bookNo >> s2.units_sold >> s2.revenue;
	cout << "s2��bookNo��units_sold��revenue�ֱ�Ϊ:" << s2.isbn() << " " << s2.units_sold << " " << s2.revenue << endl;
	Sales_data s = add(s1, s2);
	//cout << "s1+s2��bookNo��units_sold��revenue�ֱ�Ϊ:" << s1.isbn() << " " << s1.units_sold << " " << s1.revenue << endl;
	print(cout, s);*/
}