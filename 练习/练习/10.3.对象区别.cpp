#include <iostream>
using namespace std;
/*
定义类模板T_Counter，实现基本类型数据的+、-、*、=、>>、<< 运算；类模板T_Vector，实现向量运算；
类模板T_Matrix，实现矩阵运算。请分析使用类模板建立T_Counter、T_Vector、T_Matrix对象和使用类继承体系建立IntReal、Vector、Matrix对象
（见第8章综合练习的程序设计第3、4、5题）的语法区别和运算功能区别。
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