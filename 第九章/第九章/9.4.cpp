#include <iostream>
#include <vector>
using namespace std;
vector<int>::iterator f(vector<int>::iterator it1, vector<int>::iterator it2, int i)
{
	while (it1 != it2) {
		if (*it1 == i) {
			cout << "�ҵ�����ֵ" ;
			return it1;
		}
		++it1;
	}
	cout << "δ�ҵ�����ֵ" << endl;

}
int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	int i = 9;
	cout << *f(v.begin(), v.end(), i) << endl;
}