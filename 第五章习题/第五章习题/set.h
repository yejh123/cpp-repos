//�������ʾȫ��Ϊ{1,2������, 32 * N}����������
#include<iostream>
using namespace std;
const unsigned N = 4;
typedef unsigned setType[N];
void setPut(setType S);
void setDisplay(setType S);
void putX(setType S, unsigned x);
void Com(setType C, const setType A, const setType B);         //�󲢼�
void setInt(setType C, const setType A, const setType B);         //�󽻼�
void setDiff(setType C, const setType A, const setType B);            //��
bool Inc(const setType A, const setType B);              //��A������B
bool In(const setType S, unsigned x);                    //��x����S��
bool Null(const setType S);                         //�пռ�

