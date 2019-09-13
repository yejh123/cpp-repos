#pragma once
#ifndef MANAGER_H
#define MANAGER_H
/*
*	����Manager��͸�����Ϣ��������̳���ϵ
*	Manager�ࣺ�����ǽӿ��࣬�����ṩ�����ӿڣ����ڷ�װ�������ʵ��
*	base�ࣺ ����ѡ���ļ����½��ļ��Ͷ�ȡ�ļ��Ȳ���
*/
#include "Student.h"
#include "Course.h"
#include <regex>
using Student_ptr = shared_ptr<Student>;
using Course_ptr = shared_ptr<Course>;
class Student;
class Date;
class Base {
	friend class Manager;
protected:
	shared_ptr<vector<Student_ptr>> list;
	shared_ptr<vector<Course_ptr>> courseList;
public:
	Base() {
		list = make_shared<vector<Student_ptr>>();
		courseList = make_shared<vector<Course_ptr>>();
	}

	Base(shared_ptr<vector<Student_ptr>> list, shared_ptr<vector<Course_ptr>> course_list) : list(list), courseList(course_list) {}

	//======================������ѧ����Ϣ��¼����=========================
	//��ӡѧ����¼
	void print();

	//���ѧ����¼
	void add(Student stud);

	//����ѧ������������ÿ��ɾ�����޸�ѧ����¼ʱ�Զ�����
	void updateRank();

	//�ɶ�ѧ�š����������ν��������������
	void sort(int flag, bool bl);

	//�߼�ɾ��ѧ����¼
	void remove(int flag, string str);

	//�޸�ѧ����¼
	void revise(int flag, string str);

	//��ѯѧ����¼
	vector<shared_ptr<Student>> query(int flag, string str);

	//��ջ���վ
	void clear();

	//�ָ�ѧ����Ϣ��¼
	void rollback();

	//=========================�����ǿγ̲���============================
	//��ӿγ�
	void addCourse();

	//��ӡ�γ���Ϣ
	void printCourses();

	//Ϊѧ����ӳɼ�
	void addScores(vector<Student_ptr> stud);

	//=============================�麯��================================
	virtual void setLeftFile(string newFile) {
		cout << "�޷��ڻ�����ʹ��setLeftFile()" << endl;
	}
	virtual void setRightFile(string newFile) {
		cout << "�޷��ڻ�����ʹ��setRightFile()" << endl;
	}
	virtual void store() { cout << "�޷��ڻ�����ʹ��store()" << endl; }
	virtual void read() { cout << "�޷��ڻ�����ʹ��read()" << endl; }
	virtual void storeCourses() { cout << "�޷��ڻ�����ʹ��storeCourses()" << endl; }
	virtual void readCourses() { cout << "�޷��ڻ�����ʹ��readCourses()" << endl; }
	virtual void append(string str) { cout << "�޷��ڻ�����ʹ��append()" << endl; }
	virtual ~Base() {}
};

class Manager {
	shared_ptr<Base> base_ptr;
public:
	Manager(shared_ptr<Base> base_ptr) :base_ptr(base_ptr) {}
	void setBase_ptr(shared_ptr<Base> newPtr) {
		this->base_ptr = newPtr;
	}
	//=================================Manager�ӿں���========================================
	//���ѧ����¼
	void add();

	//��ӡѧ����Ϣ��¼
	void print() {
		base_ptr->print();
		cout << "\n�ѷ��ص����˵�" << endl;
	}

	//��ȡ�ļ���ѧ����Ϣ
	void read();

	//�洢��ǰѧ����Ϣ��¼���ļ���
	void store();

	//��ѧ���ı��λ��Ϊ1����ʾ�߼�ɾ��
	void remove();

	//�ָ���ɾ��ѧ����¼
	void rollback();

	//��ѯ������flagΪ1��ʾ��ѧ�Ų�ѯ��Ϊ2��ʾ��������ѯ��Ϊ3��ʾ�����β�ѯ
	void query();

	//�޸�ѧ����Ϣ
	void revise();

	//��listԪ������flagΪ1��ʾ��num����2��ʾ����������3��ʾ����������blΪ0��ʾ����Ϊ1��ʾ����
	void sort();

	//����ڴ��е�ѧ����Ϣ��¼
	void clear();			

	//��ӿγ���Ϣ
	void addCourse();

	//��ӡ��ǰ�γ���Ϣ
	void printCourses();

	//��ȡ�ļ��пγ���Ϣ
	void readCourses(); 

	//�洢��ǰ�γ���Ϣ��¼���ļ���
	void storeCourses();

	//Ϊѧ����ӿγ̳ɼ�
	void addScores();

	//ʵ�ֶ��ļ�����׷�ӵ�ͬһ���ļ�����
	void filesAppend();
};


class UnaryFile : public Base {
	friend class Manager;
protected:
	string leftFile;	//�������ļ���
	string courseFile;	//����γ��ļ���
public:
	UnaryFile(shared_ptr<vector<Student_ptr>> list, shared_ptr<vector<Course_ptr>> courseList,  const string& str1, const string & str2) : Base(list,courseList), leftFile(str1), courseFile(str2) {
		ifstream in1(str1);
		ifstream in2(str2);
		in1.close();
		in2.close();
	}
	UnaryFile(const Base& base, const string& str1, const string &str2) : Base(base), leftFile(str1), courseFile(str2) { 
		ifstream in1(str1);
		ifstream in2(str2);
		in1.close();
		in2.close();
	}
	UnaryFile(const string& str1, const string &str2) : Base(), leftFile(str1), courseFile(str2) {
		ifstream in1(str1);
		ifstream in2(str2);
		in1.close();
		in2.close();
	}
	
	//�洢ѧ����Ϣ��¼�ļ�
	virtual void store() override;		

	//��ȡѧ����Ϣ��¼�ļ�
	virtual void read() override;

	//����Ҫ��ȡ���ļ�
	virtual void setLeftFile(string newFile) override {
		this->leftFile = newFile;
	}
	//����Ҫ׷�ӵ����ļ��������ඨ�壩
	virtual void setRightFile(string newFile) override {
		cout << "�޷��ڻ�����ʹ��setRightFile()" << endl;
	}

	//�洢�γ���Ϣ��¼�ļ�
	virtual void storeCourses() override;

	//��ȡ�γ���Ϣ��¼�ļ�
	virtual void readCourses() override;

	//���ļ�׷�Ӳ����������ඨ�壩
	virtual void append(string str) override { cout << "�޷��ڻ�����ʹ��append()" << endl; }
};
class BinaryFile : public UnaryFile {
	friend class Manager;
	vector<string> studentFiles;
	string rightFile;	//�������ļ���
public:
	BinaryFile(shared_ptr<vector<Student_ptr>> list, shared_ptr<vector<Course_ptr>> courseList, const string& stud1, const string& course, const string& stud2) :UnaryFile(list, courseList, stud1, course), rightFile(stud2) {}
	BinaryFile() = default;
	BinaryFile(const string& str1, const string &str2) :UnaryFile(str1,str2){ }

	void addStudentFiles(string newFile) {
		this->studentFiles.push_back(newFile);
	}
	virtual void setRightFile(string newFile) override {
		this->rightFile = newFile;
	}
	virtual void append(string str) override;		//�����ļ���¼׷�ӵ����ļ�ĩβ
};
#endif // !MANAGER_H

