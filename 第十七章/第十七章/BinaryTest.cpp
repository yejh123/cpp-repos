#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//�������ļ�ת�ı��ļ�
void binaryToText(const char* inputFile, const char* outputFile) {
	ifstream in(inputFile, fstream::in | fstream::binary);
	ofstream out(outputFile, fstream::out);
	
	if (!in) {
		cout << "�����ļ�������" << endl;
	}
	if (!out) {
		cout << "����ļ�������" << endl;
	}
	char c[128];
	cout << "---------------binaryToText----------------" << endl;
	//cout << sizeof(data) << endl;		64
	while (in.read((char*)&c, sizeof(c))) {
		cout << c << endl;
		out << c << endl;
	}
}

//�ı��ļ�ת�������ļ�
void textToBinary(const char* inputFile, const char* outputFile) {
	ifstream in(inputFile, fstream::in);
	ofstream out(outputFile, fstream::out | fstream::binary);
	//string s;
	if (!in) {
		cout << "�����ļ�������" << endl;
	}
	if (!out) {
		cout << "����ļ�������" << endl;
	}
	cout << "---------------textToBinary----------------" << endl;
	char c[128];
	while (in.getline(c,128)) {
		cout << c << "\t" << sizeof(c) << endl;
		out.write((char*)&c, sizeof(c));
	}
	in.close();
	out.close();
}
int main() {
	string str(100,'a');
	cout << str << endl;
	cout << sizeof(str)<<" "<<str.size() << endl;
	textToBinary("Text.txt", "test.dat");
	binaryToText("test.dat", "Text1.txt");

}