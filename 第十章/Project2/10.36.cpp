#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <list>
using namespace std;
int main() {
	list<int> li{ 213, 5,  1 , 0, 5, 4, 125, 1, 1, 851, 0, 584, 0, 5, 4, 0, 65, 4 , 65, 9, 8, 0, 5456, 154 };
	auto rit1 = find(li.crbegin(), li.crend(), 0);
	++rit1;
	auto it2 = rit1.base();
	auto beg = li.cbegin();
	int i = 1;
	for (; beg != it2; ++i, ++beg);
	cout<<"最后一个"<<*it2<<"在第"<<i<<"个位置"<<endl;
}