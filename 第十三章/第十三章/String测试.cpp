#include "String.h"
#include <vector>
int main() {
	vector<String> vs; //�����
	cout << endl;
	String s("dsa");   //C���
	cout << endl;
	String s1 (s);     //�������캯��
	cout << endl;
	vs.push_back("chang"); //����C����ַ�����ʼ��������ʱ����,�ٵ��ÿ������캯��(�ƶ����캯��,������������ƶ����캯��������ʹ���ƶ����캯��)

	cout << endl;
	vs.push_back(s1);      //���ÿ���
	cout << endl;
	vs.push_back(s1);      //����
	cout << endl;
	vs.push_back(String("fji"));           //C���
	cout << endl;
	vs.push_back(std::move("dhauo"));      //C���
}