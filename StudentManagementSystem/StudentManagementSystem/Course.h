#pragma
#ifndef COURSE_H
#define COURSE_H

#include <iomanip>
#include <string>
#include <sstream>
#include <iomanip>
class Date {
	unsigned year;
	unsigned month;
	unsigned day;
public:
	Date() = default;
	Date(unsigned y, unsigned m, unsigned d) : year(y), month(m), day(d) {}
	string getDate() {
		string monthstr = month < 10 ? "0" + to_string(month) : to_string(month);
		string daystr = day < 10 ? "0" + to_string(day) : to_string(day);
		return to_string(year) + "-" + monthstr + "-" + daystr;
	}
};

/*课程类
cno 课程编号
subName 课程名称
teacherName 授课教师名称
credit 课程学分
duration 课程起止时间
*/
class Course {
	friend class Base;
	friend class UnaryFile;

	static int seq;
	int cno;
	string subName;
	string teacherName;
	double credit;
	pair<Date, Date> duration;
public:
	Course(string sn, string tn, double c, pair<Date, Date> d) :subName(sn), teacherName(tn), credit(c), duration(d), cno(seq++) { }
	Course(string sn, string tn, double c) :subName(sn), teacherName(tn), credit(c), cno(seq++) {
		Date d(2019, 1, 1);
		pair<Date, Date> p(d, d);
		duration = p;
	}
	Course(): Course("", "", 0.0){ }
	string info() {
		ostringstream os;
		os << left<<setw(10)<<this->cno << setw(30) << this->subName << setw(20) << this->teacherName << setw(10) << this->credit
			<< this->duration.first.getDate() << " ~ " << this->duration.second.getDate();
		return os.str();
	}
	int getCno() {
		return this->cno;
	}
	string getCourseName() {
		return subName;
	}
	double getCredit() {
		return this->credit;
	}
	string getTeacherName() {
		return this->teacherName;
	}
};



#endif // !COURSE_H
