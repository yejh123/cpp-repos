#include "Manager.h"
void UnaryFile::store() {		//��ȡ���ļ���¼��list��
	ofstream output;
	cout << "\n�Ƿ�Ҫ��ԭ�����ļ�(���ԭ�ļ������ݵĻ�)ĩβ׷��(1��ʾ׷�ӣ�2��ʾ����,0��ʾ�˳�)?" << endl;
	int flag;
	cout << "Demand>";
	cin >> flag;
	while (flag < 0 || flag >2) {
		cout << "\n��������! ����������!" << endl;
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
		output << left << setw(20) << "ѧ��" << setw(10) << "����" << setw(10) << "����" << setw(10) << "ƽ����" << "�γ̳ɼ�\n";
	}

	for_each(list->cbegin(), list->cend(), [&output](const Student_ptr& stud) {
		if (stud->getFlag() != 1)
			output << stud->info() << endl; });
	cout << "\n��¼�洢��" << leftFile << "�ļ��ɹ���" << endl;
	output.close();
}

void UnaryFile::read() {
	ifstream input;
	cout << "\n������Ҫ����ѧ����¼���ļ���������0��ʾ����Ĭ���ļ���:" << endl;
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
		cout << "c:\\file\\" + fname + ".txt" << "�ļ�������" << endl;
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
				cout << "\nδ����γ��ļ�����������10����γ��ļ����ٵ���ѧ����Ϣ�ļ�" << endl;
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
	cout << "\n" << leftFile << "ѧ���ļ�������ϣ����Ҫ�鿴ѧ����Ϣ��¼���밴2" << endl;
	input.close();
}

void UnaryFile::readCourses() {
	ifstream input;
	cout << "\n������Ҫ����γ̼�¼���ļ���������0��ʾ����Ĭ���ļ���:" << endl;
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
		cout <<  "c:\\file\\" << fname << ".txt�ļ������ڣ�" << endl;
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
	cout << "\n" << courseFile << "�γ��ļ�������ϣ����Ҫ�鿴�γ���Ϣ���밴11" << endl;
	input.close();

}

void UnaryFile::storeCourses() {		//��ȡ���ļ���¼��list��
	ofstream output;
	cout << "\n�Ƿ�Ҫ��ԭ�����ļ�(���ԭ�ļ������ݵĻ�)ĩβ׷��(1��ʾ׷�ӣ�2��ʾ����,0��ʾ�˳�)?" << endl;
	int flag;
	cout << "Demand>";
	cin >> flag;
	while (flag < 0 || flag >2) {
		cout << "\n��������! ����������!" << endl;
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
		output << left << setw(10) << "�γ̱��" << setw(30) << "�γ�����" << setw(20) << "�ον�ʦ" << setw(10) << "ѧ��" << "�γ���ֹʱ��\n";
	}

	for_each(courseList->cbegin(), courseList->cend(), [&output](const Course_ptr& course) {
		output << course->info() << endl;
	});
	cout << "\n��¼�洢��" << courseFile << "�ļ��ɹ���" << endl;
	output.close();
}