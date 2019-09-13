#include <iostream>
#include <type_traits>
#include <vector>
#include <typeinfo>
using namespace std;
template <typename It> 
auto f1(It beg, It end) -> typename remove_reference<decltype(*beg) >::type
{

}
template <typename It>
auto f2(It beg, It end) -> decltype(*beg + 0) 
{
	return *beg;
}
int main()
{
	vector<int> vi{ 1,2,3,4,5,6,7 };
	f2(vi.begin(), vi.end()) = 3;
	auto i = f2(vi.begin(), vi.end());
	
	cout << i <<" "<< *vi.begin()<< endl;
	cout << typeid(i).name() << endl;
}