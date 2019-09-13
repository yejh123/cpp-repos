#include <iostream>
using namespace std;
namespace A {
	int i = 16, j = 15, k = 23;
}
int j = 0;
void manip() {
	using A::i;
	using A::j;
	using A::k;
	++i;
	++j;              //¶þÒåÐÔ´íÎó
	++::j;          
	++A::j;

	++k;

	cout << "i:" << i << "	A;;j:" << j << "		::j:" << ::j << "	k:" << k << endl;

}
int main()
{
	manip();
}