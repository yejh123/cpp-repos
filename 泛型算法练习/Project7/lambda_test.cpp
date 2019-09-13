#include "Chapter10.h"
void lambda_test() {
	int i1 = 42;
	auto f = [i1]()mutable {return ++i1; };		//	¿É±älambda
	cout << f();

}