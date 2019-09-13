#include "ConstStrBlobPtr.h"
using namespace std;

int main()
{
	const StrBlob sb1 = { "fdaafg","gsda","ewpo" };
	StrBlobPtr sbp(sb1);
	cout << sb1.size() << endl;
	cout << sbp->size() << endl;
	cout << sbp.operator->() <<" "<< &sbp[0]<<endl;
	p p1(sbp);
	cout<<p1->size()<<endl;
	cout << endl;
	
}