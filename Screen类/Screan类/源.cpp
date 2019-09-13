#include <iostream>
#include <string>
#include "Screen.h"
using namespace std;
int main()
{
	Window_mge w;
	//w.print(0);
	w.set(0,3,3,'s');
	w.set(0, 3, 4, 'b');
	w.set(0, 3, 5, 'c');
	w.set(0, 3, 6, 'h');
	w.set(0, 3, 7, 'a');
	w.set(0, 3, 8, 'n');
	w.set(0, 3, 9, 'g');
	w.print(0);
}