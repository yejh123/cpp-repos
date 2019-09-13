#include "Chapter10.h"
#include <typeinfo>
using namespace std::placeholders;
void bind_test() {
	size_t sz = 5;
	auto myBind = bind([](const string & s, size_t sz)->bool {return s.size() >= sz; }, _1, sz);
	vector<string> vec = { "dans","dioqs","ahueif","eq" };
	auto first = find_if(vec.cbegin(), vec.cend(), myBind);
	cout << *first << endl;
	first = find_if(vec.cbegin(), vec.cend(), [sz](const string & s)->bool {return s.size() >= sz; });
	cout << *first << endl;
}
ostream& print(ostream& os, const string& s, char c) {
	return os << s << c;
}
void bind_reference_test() {
	vector<string> vec = { "dans","dioqs","ahueif","eq" };
	for_each(vec.cbegin(), vec.cend(), bind(print, ref(cout), _1, ' '));		//ref()返回一个对象的引用，cref()返回一个保存const引用的类
	cout << endl;
	//for_each(vec.cbegin(), vec.cend(), bind(print, cref(cout), _1, ' '));		error
	auto os = ref(cout);
	cout << typeid(os).name() << endl;
	auto cos = cref(cout);
	cout << typeid(cos).name() << endl;
}