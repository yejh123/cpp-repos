#include "Chapter10.h"
#include <iterator>
#include <list>
void insert_iterator_test() {
	list<int> list1 = { 42 };
	list<int> list2 = { 1,2,3,4 };
	front_insert_iterator<list<int>> front = front_inserter(list1);			//vector����û��push_front�����������޷�����vector��front_inserter
	copy(list2.cbegin(), list2.cend(), front);
	for_each(list1.cbegin(), list1.cend(), [](int i) {cout << i << " "; });			//�������
	cout << endl;
	
	vector<int> vec1;
	//vector<int> vec2 = { 1,2,4,8 };
	back_insert_iterator<vector<int>> back = back_inserter(vec1);			//listҲ��push_back����������Ҳ���Զ���back_inserter
	copy(list2.cbegin(), list2.cend(), back);
	for_each(vec1.cbegin(), vec1.cend(), [](int i) {cout << i << " "; });
}