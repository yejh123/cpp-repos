#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef vector<string&> type;
int main() {
	string str = "fdjia";
	string& ref = str;
	string str2 = "dajio";
	string* ptr = &ref;
	//string & * ref_ptr = &ref;		���ܶ���ָ�����õ�ָ��
	string * & ptr_ref = ptr;			//���Զ���ָ������
	cout << ptr << " " << *ptr << endl;
	cout << ptr_ref << " " << *ptr_ref << endl;

}