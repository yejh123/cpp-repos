#include <iostream>
#include <string>
using namespace std;


	int main()
	{
		int data = 5;
		while (1)
		{
			cout << cin.fail() << " " << cin.good() << endl;
			if (!cin.fail())
			{
				cout << "data=" <<data<< endl;
				cin >> data;
			}
			else
			{
				cout << cin.fail() << " " << cin.good() << endl;
				cin.clear();//���std::cin�Ĵ���״̬
				cout << cin.fail() << " " << cin.good() << endl;
				cin.ignore(100,'\n');//������뻺����
				cout << cin.fail() << " " << cin.good() << endl;
				cout << "input again" << endl;
				cout << data << endl;
				cin >> data;//�޷����룡����������ע�ͽ�����cin״̬����cin.fail()����1��
			}

			if (data == 0)
			{
				break;
			}
		}
	}
	/*
	int main()
	{
		int a = 0;
		while (true)
		{
			cin >> a;
			if (!cin) //�����ɸ�дΪcin.fail()
			{
				cout << ios::failbit << endl;
				cout << ios::eofbit << endl;
				cout << ios::badbit << endl;
				cout << ios::goodbit << endl;
				cout << endl;
				cout << "�������ʹ������������룡" << endl;
				cin.clear(); //��Ϊ��־����cin�е����б�־����Ϊ��Ч״̬
				cin.sync(); //�����
			}
			else
			{
				cout << a << endl;
				cout << ios::failbit << endl;
				cout << ios::eofbit << endl;
				cout << ios::badbit << endl;
				cout << ios::goodbit << endl;
				cout << endl;
				break;
			}
		}
		//system("pause");
	}*/
