#include "set.h"
int main()
{
	setType A = { 0 }, B = { 0 }, C = { 0 };
	cout << "input the elements of set A:\n";
	setPut(A);
	cout << A[0] << " " << A[1] << endl;
//	cout << "input the elements of set B:\n";
//	setPut(B);
//	cout << "input the elements of set C:\n";
//	setPut(C);
	cout << "A=";
	setDisplay(A);
//	cout << "B=";
	//setDisplay(B);
//	cout << "C=";
//	setDisplay(C);
}