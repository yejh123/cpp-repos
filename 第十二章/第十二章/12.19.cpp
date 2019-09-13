#include "StrBlobPtr.h"


int main()
{
	StrBlob sb1({ "sb","chang","da","s","b" });
	{
		StrBlob sb2(sb1);
		sb2.push_back("a");
		cout << sb1.size() << endl;
	}
	auto &beg = sb1.front();
	beg = "chou";
	cout << sb1.front()<<" "<<beg;

}