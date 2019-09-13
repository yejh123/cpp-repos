#include "Manager.h"
void UnaryFile::store() {		//读取左文件记录到list中
	ofstream output;
	cout << "\n是否要在原来的文件(如果原文件有内容的话)末尾追加(1表示追加，2表示覆盖,0表示退出)?" << endl;
	int flag;
	cout << "Demand>";
	cin >> flag;
	while (flag < 0 || flag >2) {
		cout << "\n输入有误! 请重新输入!" << endl;
		cout << "Demand>";
		cin >> flag;
	}
	if (flag == 0) {
		return;
	}
	else if (flag == 1) {
		output.open(leftFile, ofstream::app);
	}
	else if (flag == 2) {
		output.open(leftFile, ofstream::out);
		output << left << setw(20) << "学号" << setw(10) << "姓名" << setw(10) << "名次" << setw(10) << "平均分" << "课程成绩\n";
	}

	for_each(list->cbegin(), list->cend(), [&output](const Student_ptr& stud) {
		if (stud->getFlag() != 1)
			output << stud->info() << endl; });
	cout << "\n记录存储到" << leftFile << "文件成功！" << endl;
	output.close();
}

void UnaryFile::read() {
	ifstream input;
	cout << "\n请输入要导入学生记录的文件名（输入0表示导入默认文件）:" << endl;
	cout << "Demand>";
	string fname;
	cin >> fname;
	if (fname == "0") {
		input.open(leftFile, ifstream::in);
	}
	else {
		input.open("c:\\file\\" + fname + ".txt", ifstream::in);
	}

	if (!input) {
		cout << "c:\\file\\" + fname + ".txt" << "文件不存在" << endl;
		return;
	}
	string line;
	getline(input, line);
	while (getline(input, line)) {
		string num, name;
		int rank;
		double average;
		istringstream iss(line);
		iss >> num >> name >> rank >> average;
		string cname;
		double score;
		Student_ptr stud = make_shared<Student>(num, name, rank, average);
		int flag = 0;
		list->push_back(stud);
		while (iss >> cname) {
			string sign;
			iss >> sign >> score;
			auto iter = find_if(courseList->cbegin(), courseList->cend(), [cname](const Course_ptr& course) {
				return course->getCourseName() == cname;
			});
			if (iter == courseList->cend()) {
				cout << "\n未导入课程文件，请先输入10导入课程文件后再导入学生信息文件" << endl;
				return;
			}
			if (flag == 0) {
				
				flag++;
			}
			stud->addScore(*iter, score);
			stud->setFlag(0);
		}
	}
	this->updateRank();
	cout << "\n" << leftFile << "学生文件导入完毕，如果要查看学生信息记录，请按2" << endl;
	input.close();
}

void UnaryFile::readCourses() {
	ifstream input;
	cout << "\n请输入要导入课程记录的文件名（输入0表示导入默认文件）:" << endl;
	cout << "Demand>";
	string fname;
	cin >> fname;
	if (fname == "0") {
		input.open(courseFile, ifstream::in);
	}
	else {
		input.open(fname, ifstream::in);
	}
	if (!input) {
		cout <<  "c:\\file\\" << fname << ".txt文件不存在！" << endl;
		return;
	}
	string line;
	getline(input, line);
	while (getline(input, line)) {
		string cno, courseName, teacher, credit, beg, end, sign;
		istringstream iss(line);
		iss >> cno >> courseName >> teacher >> credit >> beg >> sign >> end;
		Date d1, d2;
		regex r("([\\d]{4})-([\\d]{1,2})-([\\d]{1,2}\\b)");
		smatch result;
		if (regex_match(beg, result, r)) {
			d1 = Date((unsigned)stoi(result[1]), (unsigned)stoi(result[2]), (unsigned)stoi(result[3]));
		}
		if (regex_match(end, result, r)) {
			d2 = Date((unsigned)stoi(result[1]), (unsigned)stoi(result[2]), (unsigned)stoi(result[3]));
		}
		pair<Date, Date> p(d1, d2);
		courseList->push_back(make_shared<Course>(courseName, teacher, stod(credit), p));
	}
	cout << "\n" << courseFile << "课程文件导入完毕，如果要查看课程信息，请按11" << endl;
	input.close();

}

void UnaryFile::storeCourses() {		//读取左文件记录到list中
	ofstream output;
	cout << "\n是否要在原来的文件(如果原文件有内容的话)末尾追加(1表示追加，2表示覆盖,0表示退出)?" << endl;
	int flag;
	cout << "Demand>";
	cin >> flag;
	while (flag < 0 || flag >2) {
		cout << "\n输入有误! 请重新输入!" << endl;
		cout << "Demand>";
		cin >> flag;
	}
	if (flag == 0) {
		return;
	}
	else if (flag == 1) {
		output.open(courseFile, ofstream::app);
	}
	else if (flag == 2) {
		output.open(courseFile, ofstream::out);
		output << left << setw(10) << "课程编号" << setw(30) << "课程名称" << setw(20) << "任课教师" << setw(10) << "学分" << "课程起止时间\n";
	}

	for_each(courseList->cbegin(), courseList->cend(), [&output](const Course_ptr& course) {
		output << course->info() << endl;
	});
	cout << "\n记录存储到" << courseFile << "文件成功！" << endl;
	output.close();
}