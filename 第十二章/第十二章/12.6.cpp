#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> * f1() {
	return new vector<int>;

}
void f2(vector<int> *vi)
{
	int i;
	while (cin >> i)
		vi->push_back(i);

}
void f3(vector<int> *vi)
{
	for (auto a : *vi)
		cout << a << " ";
	cout << endl;
	
}
int main()
{
	auto vi = f1();
	f2(vi);
	f3(vi);
	delete vi;
	vi = nullptr;
}