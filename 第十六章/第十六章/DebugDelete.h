#include <iostream>
using namespace std;
class DebugDelete
{
private:
	ostream & os;
public:
	DebugDelete(ostream & s = cerr) : os(s) { }
	template <typename T> void operator() (T *p) const 
	{
		os << "deleting unique_ptr" << endl;
		delete p;
		cout << "success" << endl;
	}
};