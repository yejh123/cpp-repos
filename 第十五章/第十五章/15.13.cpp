#include <iostream>
#include <string>
using namespace std;
struct base {
private:
	string basename;
public:
	string name() { return basename; }
	base (const string &s):basename(s) { }
	virtual void print(ostream &os) {
		os << basename;
	}
};
struct derived :public base {
private :
	int i;
public:
	derived (const string &s,int i):base(s),i(i){ }
	virtual void print(ostream &os) {
		base::print(os);
		os << " " << i;
	}
};
int main() {
	derived d("sda", 42);
	d.print(cout);
	cout << endl;
}