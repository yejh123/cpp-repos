#include "Manager.h"
void BinaryFile::append(string str) {
	this->setRightFile("c:\\file\\" + str + ".txt");
	ofstream output;
	string inputFile;
	cout << "\n是否要在文件末尾追加(1表示追加，2表示覆盖,0表示退出)?" << endl;
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
		output << left << setw(20) << "学号" << setw(10) << "姓名" << setw(10) << "名次" << setw(10) << "平均分" << "课程成绩\n";
	}
	
	cout << "\n请输入要追加的文件，不需要后缀名，可输入多个，按0可退出:" << endl;
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
			cout << "文件打开失败" << endl;
			return;
		}
		string line;
		getline(input, line);
		while (getline(input, line)) {
			output << line << endl;
		}
		input.close();
	}
	cout << "\n文件";
	for (auto iter = this->studentFiles.cbegin(); iter != this->studentFiles.cend(); ++iter) {
		cout << *iter << "  ";
	}
	cout << "追加到" << rightFile << "文件成功" << endl;
	this->studentFiles.clear();
}