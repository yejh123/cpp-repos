#include "Chapter10.h"
void lambda_test() {
	int i1 = 42;
	auto f = [i1]()mutable {return ++i1; };		//	�ɱ�lambda
	cout << f();

}