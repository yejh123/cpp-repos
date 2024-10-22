#pragma
#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <map>
#include <iomanip>
using namespace std;
class Course;
using Course_ptr = shared_ptr<Course>;


/*
num 学号
name 姓名
rank 排名
courses 报保存参加的所有课程
scores 保存学生的成绩。key=课程，value=成绩
average 课程按学分加权平均分，是rank的排行指标
flag 标记位，为0表示正常，为1表示被逻辑删除，为2表示未记录课程和成绩
*/
class Student {
private:
	string num;
	string name;
	unsigned rank;
	//vector<Course_ptr> courses;
	map<Course_ptr, double> scores;
	double average = 0;
	int flag = 0;
public:
	friend class Manager;
	friend class Base;
	Student() = default;
	Student(string num, string name, unsigned rank, double d) : num(num), name(name), rank(rank), average(d), flag(2) {}
	Student(string num, string name) : Student(num, name, 0, 0.0) {}
	/*void setCourses(Course_ptr course) {
		courses.push_back(course);

	}*/

	//返回学生的详细信息，以string对象返回
	string info() const;

	//打印学生粗略信息，直接在标准输出上打印
	//只打印学生课程成绩的前三条
	void printScorces(int flag);

	//根据学生的课程成绩求得对学分加权的平均分
	void updateAverage();

	/*为学生添加课程成绩
	Course_ptr 学生参加的课程
	double 学生的分数
	*/
	
	void addScore(Course_ptr, double);

	double getAverage() {
		return this->average;
	}
	int getFlag() {
		return this->flag;
	}
	string getNum() {
		return this->num;
	}
	string getName() {
		return this->name;
	}

	void setFlag(int i) {
		this->flag = i;
	}
	string setNum(string s) {
		return this->num = s;
	}
	string setName(string s) {
		return this->name = s;
	}
	void setRank(unsigned r) {
		this->rank = r;
	}
	
};

string studentFormHead();
#endif //PCH_H
