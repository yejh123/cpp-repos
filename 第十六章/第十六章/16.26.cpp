#include <iostream>
#include <vector>
using namespace std;
class NoDefault {
private:
	int i;
public:
	NoDefault(int i) :i(i) { }
	
};
template class vector<NoDefault>;
int main()
{
	//template class vector<NoDefault>;
	NoDefault nd(110);
	vector<NoDefault> v;
}