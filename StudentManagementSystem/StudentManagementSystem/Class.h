#pragma once
#ifndef CLASS_H
#define CLASS_H
#include "Student.h"
#include "File.h"
#include <memory>

class Class {
private:
	vector<shared_ptr<Student>> students;
	File file;
public:
	Class() = default;
	Class(vector<Student> students, File file) :students(students), file(file) {}
	Class(vector<Student> students) {
		students = students;
	}
	void setFile(File file) {
		this ->file = file;
	}
	void add(Student stud) {
		students.push_back(make_shared<Student>(stud));
		file.add();
	}
	//查询操作，flag为0表示按学号查找，为1表示按姓名查找
	shared_ptr<Student> query(const string& str, bool flag) {
		vector<shared_ptr<Student>>::const_iterator iter;
		if (flag == 0) {
			 iter = find(students.cbegin(), students.cend(), [str](shared_ptr<Student> s)->bool {return s->num == str; });
		}
		else {
			 iter = find(students.cbegin(), students.cend(), [str](shared_ptr<Student> s)->bool {return s->name == str; });
		}
		if (iter == students.cend()) {
			return {};
		}
		else {
			(*iter)->query();
			return *iter;
		}
	}
	//删除操作，flag为0表示按学号删除，为1表示按姓名删除
	bool remove(const string& str, bool flag) {
		vector<shared_ptr<Student>>::iterator iter;
		if (flag == 0) {
			iter = find(students.begin(), students.end(), [str](shared_ptr<Student> s)->bool {return s->num == str; });
		}
		else {
			iter = find(students.begin(), students.end(), [str](shared_ptr<Student> s)->bool {return s->name == str; });
		}
		if (iter == students.cend()) {
			return false;
		}
		else {
			students.erase(iter);
			return true;
		}
	}
	//修改操作，flag为0表示按学号删除，为1表示按姓名删除
	void revise(const string& str1, const string& str2, bool flag) {
		cout << "修改前学生信息:" << endl;
		shared_ptr<Student> student = query(str1, flag);
		cout << "修改后学生信息:" << endl;
		student->revise(str2,flag);
	}
};
#endif // !CLASS_H
