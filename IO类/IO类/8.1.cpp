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
				cin.clear();//清除std::cin的错误状态
				cout << cin.fail() << " " << cin.good() << endl;
				cin.ignore(100,'\n');//清空输入缓冲区
				cout << cin.fail() << " " << cin.good() << endl;
				cout << "input again" << endl;
				cout << data << endl;
				cin >> data;//无法读入！！！！消除注释将导致cin状态错误（cin.fail()返回1）
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
			if (!cin) //条件可改写为cin.fail()
			{
				cout << ios::failbit << endl;
				cout << ios::eofbit << endl;
				cout << ios::badbit << endl;
				cout << ios::goodbit << endl;
				cout << endl;
				cout << "输入类型错误，请重新输入！" << endl;
				cin.clear(); //复为标志，将cin中的所有标志设置为有效状态
				cin.sync(); //清空流
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
