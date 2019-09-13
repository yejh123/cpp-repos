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
	//1. 指针指向类  
	const A *pca1  = &A() ;
	A *pa2 = const_cast<A*>(pca1);  //常量对象转换为非常量对象  
	pa2->m_iNum = 200;    //fine  

	//转换后指针指向原来的对象  
	cout << pca1->m_iNum << pa2->m_iNum << endl; //200 200  

	//2. 指针指向基本类型  
	const int ica = 100;
	int * ia = const_cast<int *>(&ica);
	*ia = 200;
	
	cout << *ia << ica << endl;   //200 100  
}