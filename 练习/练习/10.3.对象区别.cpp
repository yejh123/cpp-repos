#include <iostream>
using namespace std;
/*
������ģ��T_Counter��ʵ�ֻ����������ݵ�+��-��*��=��>>��<< ���㣻��ģ��T_Vector��ʵ���������㣻
��ģ��T_Matrix��ʵ�־������㡣�����ʹ����ģ�彨��T_Counter��T_Vector��T_Matrix�����ʹ����̳���ϵ����IntReal��Vector��Matrix����
������8���ۺ���ϰ�ĳ�����Ƶ�3��4��5�⣩���﷨��������㹦������
*/
template<typename T>
class T_Counter {
	T data;
};
template<typename T>
class T_Vector : public T_Count<T> {

};
template<typename T>
class T_Matrix : public T_Vector<T>{

};
int main(){

}