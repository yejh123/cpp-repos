#include "String.h"
#include <vector>
using namespace std;

int main() {
	vector<String> vs;;
	vs.reserve(4);
	String s0 = "sad", s1("dsaf"), s3("jfu"), s4("ajgo");
	cout << endl;
	vs.push_back(s0);
	cout << endl;
	
	vs.push_back(std::move(s1));
	cout << endl;
	vs.push_back(String("dsaff"));
	cout << endl;
	vs.push_back("sdjao");
	cout << endl;
}