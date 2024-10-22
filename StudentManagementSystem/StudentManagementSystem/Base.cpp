#include "Manager.h"

class Student;
class Date;

void Base::print() {
	if (!list->empty()) {
		cout << "\n当前表单已有如下学生信息记录:\n" << endl;
		cout << left << setw(20) << "学号" << setw(10) << "姓名" << setw(10) << "名次" << setw(10) << "平均分" << "课程成绩\n"
			<< "------------------  --------  --------  --------  ---------------------------------------------------------------" << endl;
		for_each(list->cbegin(), list->cend(), [](const Student_ptr& stud) {
			if (stud->flag == 0)
				stud->printScorces(0);
		});
		for_each(list->cbegin(), list->cend(), [](const Student_ptr& stud) {
			if (stud->flag == 2)
				stud->printScorces(0);
		});
	}
	else {
		cout << "\n当前表单无任何学生信息记录!" << endl;
	}
}

void Base::add(Student stud) {
	list->push_back(make_shared<Student>(stud));
	cout << "\n添加学生记录成功!" << endl;
}

void Base::updateRank() {
	::sort(list->begin(), list->end(), [](const Student_ptr& stud1, const Student_ptr& stud2)-> bool {return stud1->getAverage() > stud2->getAverage(); });
	int cnt = 1, temp;
	double last;
	for (auto iter = list->begin(); iter != list->end(); ++iter, ++cnt) {
		if ((*iter)->getFlag() != 0) {
			--cnt;
			continue;
		}
		if (cnt == 1) {
			last = (*iter)->getAverage();
			(*iter)->rank = 1;
			temp = 1;
		}
		else {
			if (abs((*iter)->getAverage() - last) < 0.00001) {
				(*iter)->rank = temp;
			}
			else {
				last = (*iter)->getAverage();
				temp = (*iter)->rank = cnt;
			}
		}
	}
}

void Base::sort(int flag, bool bl) {
	if (flag == 1) {
		if (bl == 0)
			::sort(list->begin(), list->end(), [](const Student_ptr& stud1, const Student_ptr& stud2)-> bool {return stud1->num < stud2->num; });
		else {
			::sort(list->begin(), list->end(), [](const Student_ptr& stud1, const Student_ptr& stud2)-> bool {return stud1->num >= stud2->num; });
		}
	}
	else if (flag == 2) {
		if (bl == 0) {
			::sort(list->begin(), list->end(), [](const Student_ptr& stud1, const Student_ptr& stud2)-> bool {return stud1->name < stud2->name; });
		}
		else {
			::sort(list->begin(), list->end(), [](const Student_ptr& stud1, const Student_ptr& stud2)-> bool {return stud1->name >= stud2->name; });
		}
	}
	else if (flag == 3) {
		updateRank();
		if (bl) {
			::reverse(list->begin(), list->end());
		}
	}
}

void Base::remove(int flag, string str) {
	vector<shared_ptr<Student>> vec = query(flag, str);
	unsigned i = 1;
	if (vec.size() > 1) {
		cout << "\n请选择您要删除的学生记录是第几条(从1开始数): " << endl;
		cout << "Demand>";
		cin >> i;
		while (i > vec.size()) {
			cout << "\n输入有误，请重新输入，数字应从1到" << vec.size() << endl;
			cout << "Demand>";
			cin >> i;
		}
	}
	Student_ptr stud = vec[i - 1];
	for (auto iter = list->begin(); iter < list->end(); ++iter) {
		if ((*iter)->num == stud->num) {
			(*iter)->flag = 1;
			break;
		}
	}
	this->updateRank();
	cout << "\n删除成功" << endl;
}

void Base::revise(int flag, string str) {
	vector<shared_ptr<Student>> vec = query(flag, str);
	if (vec.empty()) {
		return;
	}
	unsigned i = 1;
	if (vec.size() > 1) {
		cout << "\n请选择您要修改的学生记录是第几条(从1开始数，按0可退出): " << endl;
		cout << "Demand>";
		cin >> i;
		while (i== 0 || i > vec.size()) {
			if (i == 0) {
				return;
			}
			cout << "\n输入有误，请重新输入，数字应从1到" << vec.size()<<"（按0可退出）" << endl;
			cout << "Demand>";
			cin >> i;
		}
	}
	shared_ptr<Student> stud = vec[i - 1];
	cout << "\n请选择你要修改该生的什么信息(修改学号请按1，修改姓名请按2):";
	int flag2;
	cout << "Demand>";
	cin >> flag2;
	while (flag2 < 1 && flag2 > 2) {
		cout << "\n输入错误，请重新输入。若要退出请按0" << endl;
		cout << "Demand>";
		cin >> flag2;
		if (flag2 == 0) {
			return;
		}
	}
	cout << "\n请输入修改后的新内容" << endl;
	string newstr;
	cout << "Demand>";
	cin >> newstr;
	if (flag2 == 1) {
		stud->num = newstr;
	}
	else if (flag2 == 2) {
		stud->name = newstr;
	}
	cout << "\n修改成功!修改后的学生信息如下:" << endl;
	cout << studentFormHead();
	cout << stud->info() << endl;
}

vector<shared_ptr<Student>> Base::query(int flag, string str) {
	vector<Student_ptr>::iterator iter = list->begin();
	vector<Student_ptr> vec;
	cout << "\n符合要求的学生如下: " << endl;
	if (flag == 1) {
		iter = find_if(list->begin(), list->end(), [str](const Student_ptr& stud) {return stud->num == str; });
	}
	if (flag == 2) {
		iter = find_if(list->begin(), list->end(), [str](const Student_ptr& stud) {return stud->name == str; });
	}
	if (flag == 3) {
		while (iter != list->cend()) {
			iter = find_if(iter, list->end(), [str](const Student_ptr& stud) {return stud->rank == stoi(str); });
			if (iter == list->cend())
				break;
			if ((*iter)->getFlag() != 1) {
				vec.push_back(*iter);
			}
			++iter;
		}
		if (!vec.empty()) {
			cout << studentFormHead();
			for (unsigned i = 0; i < vec.size(); ++i) {
				cout << vec[i]->info() << endl;
			}
		}
		else {
			cout << "符合要求学生不存在!" << endl;
		}
		return vec;
	}
	if (iter != list->cend()) {
		cout << studentFormHead();
		cout << (*iter)->info() << endl;
		vec.push_back(*iter);
	}
	else {
		cout << "符合要求学生不存在!" << endl;
	}
	return vec;
}

void Base::clear() {
	for (auto iter = this->list->begin(); iter != this->list->cend(); ) {
		if ((*iter)->getFlag() == 1) {
			iter = this->list->erase(iter);
		}
		else {
			++iter;
		}
	}
}

void Base::rollback() {
	vector<shared_ptr<Student>> vec;
	if (this->list->empty()) {
		cout << "\n当前没有任何学生记录" << endl;
		return;
	}
	
	for (auto iter = this->list->begin(); iter != this->list->cend(); ++iter) {
		int flag = 0;
		if ((*iter)->getFlag() == 1) {
			if (flag == 0) {
				cout << studentFormHead();
				++flag;
			}
			vec.push_back(*iter);
			cout << (*iter)->info() << endl;
		}
	}

	unsigned i = 1;
	if (vec.empty()) {
		cout << "\n当前回收站中没有学生记录！" << endl;
		return;
	}
	else  {
		cout << "\n请选择您要恢复的学生记录是第几条(从1开始数，按0可退出): " << endl;
		cout << "Demand>";
		cin >> i;
		while (i > vec.size() || i == 0) {
			if (i == 0) {
				return;
			}
			cout << "\n输入有误，请重新输入，数字应从1到" << vec.size() <<"（按0可退出）"<< endl;
			cout << "Demand>";
			cin >> i;
		}
	}
	shared_ptr<Student> stud = vec[i - 1];
	stud->setFlag(0);
	this->updateRank();
	cout << "\n恢复学生记录成功!" << endl;
}

void Base::addCourse() {
	cout << "您可以一直添加多条课程信息，按0可退出" << endl;

	string subjectName, teacherName;
	double credit;
	while (1) {
		cout << "\n请依次输入课程的名称、任课教授名字、课程学分(按0可退出):" << endl;
		cout << "Demand>";
		cin >> subjectName;
		if (subjectName == "0") {
			cout << "\n已返回到主菜单，若要查看课程记录请按11，保存课程记录请按14" << endl;
			break;
		}
		cin >> teacherName >> credit;
		if (!cin) {
			cout << "\n学分只能填入数字! \n添加学生记录失败，已返回到主菜单!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}
		string str1, str2;
		Date beg, end;

		cout << "\n请输入课程的起始时间，例如2018-03-01(按0表示输入默认起始时间):" << endl;
		cout << "Demand>";
		cin >> str1;
		regex r("([\\d]{4})-([\\d]{1,2})-([\\d]{1,2}\\b)");
		smatch result;
		if (str1 != "0") {
			while (!regex_match(str1, result, r)) {
				cout << "\n日期输入有误，请重新输入，例如2019-03-01(按0表示输入默认起始时间):" << endl;
				cout << "Demand>";
				cin >> str1;
			}
			beg = Date((unsigned)stoi(result[1]), (unsigned)stoi(result[2]), (unsigned)stoi(result[3]));
		}
		else {
			beg = Date(2019, 3, 1);
		}

		cout << "\n请输入课程的结束时间，例如2018-07-01(按0表示输入默认结束时间):" << endl;
		cout << "Demand>";
		cin >> str2;
		if (str2 != "0") {
			while (!regex_match(str2, result, r)) {
				cout << "\n日期输入有误，请重新输入，例如2018-07-01(按0表示输入默认结束时间):" << endl;
				cout << "Demand>";
				cin >> str2;
			}
			end = Date((unsigned)stoi(result[1]), (unsigned)stoi(result[2]), (unsigned)stoi(result[3]));
		}
		else {
			end = Date(2019, 7, 1);
		}
		pair<Date, Date> p(beg, end);
		Course_ptr course = make_shared<Course>(subjectName, teacherName, credit, p);
		this->courseList->push_back(course);
	}
}
void Base::printCourses() {
	if (!courseList->empty()) {
		cout << "\n当前表单已记录有如下课程:" << endl;
		cout << left << setw(10) << "课程编号" << setw(30) << "课程名称" << setw(20) << "任课教师" << setw(10) << "学分" << "课程起止时间\n"
			<< "--------" << "  ----------------------------" << "  ------------------" << "  --------"
			<< "  --------------------------------------------------" << "\n";
		for_each(courseList->cbegin(), courseList->cend(), [](const Course_ptr& course) {
			cout << course->info() << endl;
			//cout << course->subName << "\t" << course->teacherName << "\t" << to_string(course->credit).substr(0, 3) << "\t" << course->duration.first.getDate() << "~" << course->duration.second.getDate() << endl;
		});
	}
	else {
		cout << "\n当前表单无任何课程记录!" << endl;
	}
}

void Base::addScores(vector<Student_ptr> vec) {
	if (vec.empty()) {
		return;
	}
	unsigned i = 1;
	if (vec.size() > 1) {
		cout << "\n请选择您要增加课程成绩的学生记录是第几条(从1开始数): " << endl;
		cout << "Demand>";
		cin >> i;
		while (i < 1 || i > vec.size()) {
			cout << "\n输入有误，请重新输入，数字应从1到" << vec.size() << endl;
			cout << "Demand>";
			cin >> i;
		}
	}
	shared_ptr<Student> stud = vec[i - 1];
	stud->setFlag(0);
	cout << "\n当前已保存有如下课程信息" << endl;
	this->printCourses();

	unsigned flag2;
	cout << "您可以一直为该生添加多次课程成绩，按0可退出" << endl;
	while (1) {
		cout << "\n请选择您要添加第几条课程的成绩，按0可退出:" << endl;;
		cout << "Demand>";
		cin >> flag2;
		if (flag2 == 0) {
			break;
		}
		while (flag2 < 1 || flag2 > courseList->size()) {
			cout << "\n输入有误，请重新输入，数字应从1到" << courseList->size() << endl;
			cout << "Demand>";
			cin >> flag2;
		}
		Course_ptr course = (*courseList)[flag2 - 1];
		cout << "\n选择课程成功，请输入该生的课程成绩（百分制）" << endl;;
		double d;
		cout << "Demand>";
		cin >> d;
		while (d < 0 || d > 100) {
			cout << "\n分数输入有误，请重新输入，分数应从0到100" << endl;
			cout << "Demand>";
			cin >> d;
		}
		stud->scores[course] = d;
		cout << "\n添加成绩成功" << endl;
	}
	cout << "\n添加课程成绩结束，该生课程成绩如下" << endl;
	stud->updateAverage();
	this->updateRank();
	cout << studentFormHead();
	cout << stud->info() << endl;
}
