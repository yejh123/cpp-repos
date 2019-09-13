#include "StrBlob.h"
#include <fstream>
int main()
{
	ifstream in("data.txt");
	StrBlob sb;
	read(in, sb);
	auto sbp = sb.beg();
	print(cout, sbp);
}