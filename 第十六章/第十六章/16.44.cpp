#include <iostream>
using namespace std;
template<typename T> void f3(T&& i) {
	cout << i << endl;
	++i;
	cout << i << endl;
}
class Test {
	int * arr{ nullptr };
public:
	Test() :arr(new int[5000]{ 1,2,3,4 }) {
		cout << "default constructor	this = "<<this << endl;
	}
	Test(const Test & t) {
		cout << "copy constructor" << endl;
		if (arr == nullptr) arr = new int[5000];
		memcpy(arr, t.arr, 5000 * sizeof(int));
	}
	Test(Test && t) : arr(t.arr) {
		cout << "move constructor" << endl;
		t.arr = nullptr;
	}
	~Test() {
		cout << "destructor" << endl;
		delete[] arr;
	}
};
Test createTest() {
	return Test();
}

int main() {
	Test t(createTest());
}