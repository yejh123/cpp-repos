#include "Chapter10.h"
void equalTest() {
	const char* p[] ={ "hello", "world" };
	char* q[] = { _strdup(p[0]), _strdup(p[1]) };
	const char *r[] = { p[0], p[1] };
	cout << equal(begin(p), end(p), q) << endl;		//���ָ���Ƿ���ȣ�����������
	cout << equal(begin(p), end(p), r) << endl;

}