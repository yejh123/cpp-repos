//用数组表示全集为{1,2，……, 32 * N}的整数集合
#include<iostream>
using namespace std;
const unsigned N = 4;
typedef unsigned setType[N];
void setPut(setType S);
void setDisplay(setType S);
void putX(setType S, unsigned x);
void Com(setType C, const setType A, const setType B);         //求并集
void setInt(setType C, const setType A, const setType B);         //求交集
void setDiff(setType C, const setType A, const setType B);            //求差集
bool Inc(const setType A, const setType B);              //判A包含于B
bool In(const setType S, unsigned x);                    //判x属于S；
bool Null(const setType S);                         //判空集

