#include <iostream>
using namespace std;
template<typename T,size_t t>
void print(const T(&r)[t]) {
	for (auto &i : r) {
		cout << i << " ";
	}
	cout << endl;
}
template<typename T,size_t t>
T *begin1(T(&r)[t]) {
	return r;
}
template<typename T, size_t t>
T *end1(T(&r)[t]) {
	return &r[t];
}
template<typename T,size_t t>
constexpr unsigned get_size(const T(&r)[t]) {
	return t;
}
int main()
{
	const char s[] = "cnm";
	int ri[]{ 1,2,3,4,5 };
	print(ri);
	auto it1 = begin1(ri), it2 = end1(ri);
    cout<<*it1<<" "<<*(it2-1)<<endl;
	cout << get_size(s) << endl;
}