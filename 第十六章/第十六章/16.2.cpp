#include <iostream>
#include "Sales_data.h"

using namespace std;
template<typename T>
int compare(const T &v1, const T &v2)
{
	cout << "类型参数版本compare" << endl;
	if (v1 < v2)
		return -1;

	if (v2 < v1)
		return 1;
}
template<unsigned i1, unsigned i2>
int compare(const char(&p1)[i1], const char(&p2)[i2])
{
	cout << "数组版本compare" << endl;
	return strcmp(p1, p2);
}

int main()
{

	cout << compare("dsho", "ouho") << endl;
	cout << compare((string)"asjdo", (string)"asfji") << endl;
	Sales_data s1("1-555-89"), s2("1-555-89");
	cout << compare(s1, s2) << endl;
}