#include<iostream>
#include <string>
#include <fstream>
using namespace std;
struct student
{
	string name;
	int num;
	int age;
	char sex;
};
int main()
{
	int i = 100;
	ofstream out("test.dat", ios::binary);
	out.write((char*)&i, sizeof(int));
	out.close();
	ifstream in("test.dat", ios::binary);
	int i2;
	in.read((char*)&i2, sizeof(int));
	cout << i2 << endl;
}