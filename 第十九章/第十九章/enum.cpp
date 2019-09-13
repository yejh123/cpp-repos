#include <iostream>
using namespace std;
enum intValues : unsigned long long {
	charTyp = 255,	shortTyp = 65535,	intYpe = 65535,
	longTyp = 42949672954895489ULL
};
int main() {
	//intValues iv1 = longTyp;
	//cout << iv1 << endl;
	const char * c1 = "odahssakhj";
	char name[20];
	strncpy(name, c1, sizeof(name));
//	name[19] = '\0';
	cout << name << endl;
}