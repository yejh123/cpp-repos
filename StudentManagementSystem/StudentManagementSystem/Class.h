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
	//��ѯ������flagΪ0��ʾ��ѧ�Ų��ң�Ϊ1��ʾ����������
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
	//ɾ��������flagΪ0��ʾ��ѧ��ɾ����Ϊ1��ʾ������ɾ��
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
	//�޸Ĳ�����flagΪ0��ʾ��ѧ��ɾ����Ϊ1��ʾ������ɾ��
	void revise(const string& str1, const string& str2, bool flag) {
		cout << "�޸�ǰѧ����Ϣ:" << endl;
		shared_ptr<Student> student = query(str1, flag);
		cout << "�޸ĺ�ѧ����Ϣ:" << endl;
		student->revise(str2,flag);
	}
};
#endif // !CLASS_H
