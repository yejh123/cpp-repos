/*
������ģ����β�������ʱ���޷�������ת��Ϊָ�룡��������ͨ�����β����������ֵĲ�ͬ
���κ�����£����޷���ָ��ת��Ϊ��������ã�
*/
#include <iostream>
#include <string>
using namespace std;

//��ָ��
void fun1(char (&c)[20]) {
	cout << "fun1 " << typeid(c).name() << endl;

	cout << c << endl;
}

//����������
void fun2(char c[20]) {
	cout << "fun2 " << typeid(c).name() << endl;
	cout << c << endl;

}

void fun3(const char* const & c) {
	cout << "fun3 " << typeid(c).name() << endl;
	cout << c << endl;
}

template<typename T> int compare(const T& t1, const T& t2) {
	cout << "T����: " << typeid(T).name() << "\t" << "t1����: " << typeid(t1).name() << endl;
	cout << "t1: " << t1 << "\tt2: " << t2 << endl;
	if (t1 < t2) {
		return -1;
	}
	else if (t1 > t2) {
		return 1;
	}
	else {
		return 0;
	}
}

template<size_t N, size_t M> int compare(const char(&c1)[N], const char(&c2)[M]) {
	
	cout << "c1����: " << typeid(c1).name() << endl;
	return strcmp(c1, c2);
}

template<> int compare(const char* const &c1, const char* const &c2) {
	cout << "ģ��������" << endl;
	cout << "c1����: " << typeid(c1).name() << endl;
	return strcmp(c1, c2);
}
int main() {
	char p1[20] = "dsajuio";
	char p2[20] = "dsajuio";
	cout << (void*)p1 << "\t" << (void*)p2 << endl;		//p1��p2��ַ��ͬ��
	cout << compare(p1, p2) << endl;		//����ģ�庯�����ɵ��ã������ȵ���int compare(const char (&c1)[N], const char (&c2)[M])��������������
	cout << endl;

	int a[10], b[10];
	cout << compare(a, b) << endl;			//����template<typename T> int compare(const T& t1, const T& t2)���Ƚϵ�ֵַ
											//�����������Сǡ����ȣ��ʴ����������ã�T����Ϊint [10], �β�����Ϊint const [10]
	cout << endl;


	const char* p11 = "his", *p22 = "abc";
	cout << compare(p11, p22) << endl;		//�����ַ�ָ�룬�����޷���һ��ָ��ת��Ϊһ����������ã�����ֻ�ܵ���template<typename T> int compare(const T& t1, const T& t2)
	cout << endl;

	cout << compare("hi", "his") << endl;	//�����������ã�����int compare(const char (&c1)[N], const char (&c2)[M]
											//�޷�����template<typename T> int compare(const T& t1, const T& t2)����Ϊ�β���һ�����ã����鲻��ת��Ϊָ�룡����
	cout << endl;

	cout << compare("hi", "hi") << endl;	//����ģ�庯�����ɵ��ã������ȵ���int compare(const char (&c1)[N], const char (&c2)[M])

	fun3(p1);
	
}