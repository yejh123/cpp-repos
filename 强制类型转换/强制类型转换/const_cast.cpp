/*
1������ָ�뱻ת���ɷǳ�����ָ�룬������Ȼָ��ԭ���Ķ���
2���������ñ�ת���ɷǳ��������ã�������Ȼָ��ԭ���Ķ���
3��const_castһ�������޸�ָ�롣��const char *p��ʽ��
*/
#include<iostream>
#include <string>
using namespace std;
void test1() {
	string str1 = "abc";			//����Ϊ�ǳ�������
	const string* p1 = &str1;		//����Ϊconstָ��
	string* p2 = const_cast<string*>(p1);		//ʹ��ȥconst ָ��
	cout << str1 << "\t" << *p1 << "\t" << *p2 << endl;		//�Ϸ���Ϊ
	*p2 = "efg";
	cout << str1 << "\t" << *p1 << "\t" << *p2 << endl;

	/* �� vs2017 �� ���Ϊ
		abc abc abc	
		efg efg efg
	*/
}
void test2() {
	const int c_val = 233;  //����Ϊ��������
	int &use_val = const_cast<int&>(c_val); //ʹ��ȥconst ����
	int *ptr_val = const_cast<int*>(&c_val);//ʹ��ȥconst ָ��

	use_val = 666;  //δ������Ϊ
	std::cout << c_val << "\t" << use_val << "\t" << *ptr_val << std::endl;
	*ptr_val = 110; //δ������Ϊ
	std::cout << c_val << "\t" << use_val << "\t" << *ptr_val << std::endl;
	std::cout << &c_val << "\t" << &use_val << "\t" << ptr_val << std::endl;

	/* �� vs2017 �� ���Ϊ
		233 666 666
		233 110 110
	*/
}
int main() {
	test1();
	test2();
}