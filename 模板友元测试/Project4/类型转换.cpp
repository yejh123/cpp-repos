#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A()
	{
		m_iNum = 0;
	}

public:
	int m_iNum;
};

int main()
{
	//1. ָ��ָ����  
	const A *pca1  = &A() ;
	A *pa2 = const_cast<A*>(pca1);  //��������ת��Ϊ�ǳ�������  
	pa2->m_iNum = 200;    //fine  

	//ת����ָ��ָ��ԭ���Ķ���  
	cout << pca1->m_iNum << pa2->m_iNum << endl; //200 200  

	//2. ָ��ָ���������  
	const int ica = 100;
	int * ia = const_cast<int *>(&ica);
	*ia = 200;
	
	cout << *ia << ica << endl;   //200 100  
}