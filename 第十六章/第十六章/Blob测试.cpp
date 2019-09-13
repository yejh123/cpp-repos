#include <iostream>
#include <string>
#include "Blob.h"
using namespace std;
int main()
{
	Blob<string> sb1({ "so","sdhoa","cnm","qio" }), sb2({ "so","sdhoa","cnm","qio" }), sb3(sb1);
	BlobPtr<string> sbp1(sb1), sbp2(sb2) ;
	cout << sb1.size() << " " << sbp1->size() << endl;
	cout << (sb1 == sb2) << " " <<(sb1 == sb3) <<" "<< (sbp1 == sbp2)  << endl;
}
