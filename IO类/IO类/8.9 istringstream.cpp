#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string s;
istream& f(istream& is)
{
	string v;
	while (is>>v, !is.eof())//P.S.���Ų����滻��&& ��C++pimer P140
	{
		
		//cout << is.fail() << " " << is.eof() << endl;
		if (is.fail()) {
			cout << is.fail() << endl;
			cerr << "�������,����������" << endl;
			is.clear();
			is.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	//cout << is.fail() << " " << is.eof() << endl;
	is.clear();
	//cout << is.fail() << " " << is.eof() << endl;
	return is;
}
int main()
{
	ostringstream msg;
	msg << "sb chang shi sb" << endl;
	//istringstream in("sb chang shi sb a"); //��is��ȡ��aʱ������"�ļ�����"�źţ���is.eof()����1������a���ᱻ�������"sb chang shi sb a"����msg�ɽ��������.
	cout << msg.str() << endl;
	istringstream in(msg.str());
	f(in);
	return 0;
}
