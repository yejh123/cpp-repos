#include <iostream> 
using namespace std;
/*
��cin.rdstate()����0(��ios::goodbit)ʱ��ʾ�޴���, ���Լ���������߲���
������4��������������ios::failbit, ���ܼ�����������.��cin.clear����Կ������Ǵ�ʱcin�����������һ����ʶ.�﷨����:
cin.clear(��ʶ��);
��ʶ����Ϊ:
goodbit �޴��� 0
Eofbit �ѵ����ļ�β 1
failbit ������������ / ������󣬿���� 2
badbit������������ / �������, �޷���� 3
*/
int main()
{
	int a;
	cout << ios::goodbit << " " << ios::failbit << " " << ios::badbit << " " << ios::eofbit << endl;
	while (1)
	{
		cin >> a;
		cout << "cin.rdstate():" << cin.rdstate() << endl;
		if (cin.fail())            //�����ɸ�дΪcin.fail() 
		{
			cout << "�����д�!����������" << endl;
			cin.clear(ios::goodbit);
			cin.ignore();   //�����
		}
		else
		{
			cout << a;
			break;
		}
	}
	system("pause");
}