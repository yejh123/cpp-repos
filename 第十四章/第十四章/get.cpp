#include<iostream>
using namespace std;
int main()
{
	char input[5], s[6];
	/*for (int i = 0; i < 5; ++i)
	{
		cin.get(input[i]);
		cout << input[i];
	}*/

	//cin.get(input, 6);      //��������һ���ַ����ǡ�\0����������ַ���ĿΪn��
	                        //���������ַ������ڵ���n����ʵ�ʽ��յ����������ַ�����ǰ��n-1���ַ���
	                        //�����ո񣨲������س��������س��ͽ����ˣ������Զ��ں�������һ����\0����
	//cout << input;  

	cin.get(input, 5);
	cin.get(input, 5);          //get�����������ٶ�ȡ���������з������ǽ����з����浽������
	//cin.get(s,6);
	cin.get();                  //��������ַ�����5����cin.get()�޷��������з�
	cin.get(s, 6);
	cout << input << " " << s << endl;
}