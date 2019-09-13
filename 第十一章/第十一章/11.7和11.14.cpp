#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
void add_family(map < string, vector< pair<string, string> > > &m, const string &family) {
	m[family];
}
void add_children(map < string, vector< pair<string, string> > > &m,const string &family, const string &name,const string &birthday) {
	m[family].push_back( make_pair(name,birthday) );
}
int main()
{
	map < string, vector< pair<string, string> > > families;
	string family,name,birthday;
	cout << "输入要添加的家庭" << endl;
	while (cin >> family)
	{
		add_family(families,family);
		cout << "输入该家庭的孩子的名字和生日" << endl;
		while (cin >> name , cin>>birthday)
			add_children(families, family, name , birthday);
		cin.clear();
		cout << "是否还要输入新的家庭(1 or 0)?" << endl;
		bool bl;
		cin >> bl;
		if (!bl)
			break;

	}
	
	for (auto a : families) {
		cout << "family:";
		cout << a.first << "	";
		cout << "child's name and birthday:";
		for (auto a1 : a.second)
			cout << a1.first << " "<<a1.second<<"	";
		cout << endl;
	}
	cout << endl;
}
