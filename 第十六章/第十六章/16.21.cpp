#include "DebugDelete.h"
#include <string>
#include <memory>
using namespace std;
int main()
{
	string s1 =  ("nfaon");
	string *sp1 = new string("dsa");
	DebugDelete d;
	cout << *sp1 << endl;
	d(sp1);
	//cout << *sp1 << endl;          对象已销毁

}