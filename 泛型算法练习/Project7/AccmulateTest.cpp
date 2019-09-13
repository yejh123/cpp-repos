
#include "Only-readAlgorithm.h"
void accumulateTest() {
	vector<string> v = { "he", "llo", " world" };
	string sum = accumulate(v.cbegin(), v.cend(), (string)"");
//	string sum = accumulate(v.cbegin(), v.cend(), "");			 //error 不能将const char *作为第三个参数，因为没实现+运算符
	cout << sum << endl;;
}
void accumulateTest2() {
	vector<double> vd({ 2.5,6.5,3.1 });
	double d1 = accumulate(vd.cbegin(), vd.cend(), 0);			//警告, accumulate将使用int定义的+运算符
	double d2 = accumulate(vd.cbegin(), vd.cend(), 0.0);
	cout << d1 <<" "<<d2<< endl;
}
