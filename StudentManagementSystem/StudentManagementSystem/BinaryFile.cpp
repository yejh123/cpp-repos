#include "Manager.h"
void BinaryFile::append(string str) {
	this->setRightFile("c:\\file\\" + str + ".txt");
	ofstream output;
	string inputFile;
	cout << "\n�Ƿ�Ҫ���ļ�ĩβ׷��(1��ʾ׷�ӣ�2��ʾ����,0��ʾ�˳�)?" << endl;
	int flag;
	cout << "Demand>";
	cin >> flag;
	if (flag == 0) {
		return ;
	}
	else if (flag == 1) {
		output.open(rightFile, ofstream::app);
	}
	else if (flag == 2) {
		output.open(rightFile, ofstream::ate);
		output << left << setw(20) << "ѧ��" << setw(10) << "����" << setw(10) << "����" << setw(10) << "ƽ����" << "�γ̳ɼ�\n";
	}
	
	cout << "\n������Ҫ׷�ӵ��ļ�������Ҫ��׺����������������0���˳�:" << endl;
	cout << "Demand>";
	while (cin >> inputFile) {
		if (inputFile == "0") {
			break;
		}
		this->addStudentFiles("c:\\file\\" + inputFile + ".txt");
		cout << "Demand>";

	}
	ifstream input;
	for (auto iter = this->studentFiles.cbegin(); iter != this->studentFiles.cend(); ++iter) {
		input.open(*iter);
		if (!input) {
			cout << "�ļ���ʧ��" << endl;
			return;
		}
		string line;
		getline(input, line);
		while (getline(input, line)) {
			output << line << endl;
		}
		input.close();
	}
	cout << "\n�ļ�";
	for (auto iter = this->studentFiles.cbegin(); iter != this->studentFiles.cend(); ++iter) {
		cout << *iter << "  ";
	}
	cout << "׷�ӵ�" << rightFile << "�ļ��ɹ�" << endl;
	this->studentFiles.clear();
}