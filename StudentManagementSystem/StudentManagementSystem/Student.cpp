#include "Student.h"
#include "Course.h"
int Course::seq = 10000;

string studentFormHead() {
	ostringstream os;
	os << left << setw(20) << "学号" << setw(10) << "姓名" << setw(10) << "名次" << setw(10) << "平均分" << "课程成绩\n"
		<< "------------------  --------  --------  --------  ---------------------------------------------------------------\n";
	return os.str();
}


string Student::info()const {
	ostringstream oss;
	oss << left << setw(20) << this->num << setw(10) << this->name << setw(10) << this->rank << setw(10) << this->average;
	for (auto iter = scores.cbegin(); iter != scores.cend(); ++iter) {

		oss << iter->first->getCourseName() << " : " << iter->second << "  ";
	}
	return oss.str();
}

void Student::printScorces(int flag) {
	if (flag == 1) {
		cout << studentFormHead();
	}
	unsigned cnt = 1;
	const unsigned MAX = 3;
	cout<< left << setw(20) << this->num << setw(10) << this->name << setw(10) << this->rank << setw(10) << this->average;
	for (auto iter = scores.cbegin(); iter != scores.cend() && cnt <= MAX; ++iter, ++cnt) {
		cout << iter->first->getCourseName() << ": " << iter->second << "  ";
	}
	if (cnt <= scores.size())
		cout << "...";
	cout << endl;
}
void Student::updateAverage() {
	double totalScore = 0.0;
	double totalCredit = 0.0;
	for (auto iter = scores.cbegin(); iter != scores.cend(); ++iter) {
		Course_ptr course = iter->first;
		double credit = course->getCredit();
		totalScore += iter->second * credit;
		totalCredit += credit;
	}
	this->average = totalScore / totalCredit;
}

void Student::addScore(Course_ptr course, double score) {
	scores[course] = score;
}

