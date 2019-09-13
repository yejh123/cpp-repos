#pragma once
#ifndef MANAGER_H
#define MANAGER_H
/*
*	定义Manager类和负责信息操作的类继承体系
*	Manager类：本质是接口类，对外提供操作接口，对内封装具体操作实现
*	base类： 负责选定文件、新建文件和读取文件等操作
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

	//======================以下是学生信息记录操作=========================
	//打印学生记录
	void print();

	//添加学生记录
	void add(Student stud);

	//更新学生名次排序，在每次删除、修改学生记录时自动调用
	void updateRank();

	//可对学号、姓名、名次进行升序或降序排序
	void sort(int flag, bool bl);

	//逻辑删除学生记录
	void remove(int flag, string str);

	//修改学生记录
	void revise(int flag, string str);

	//查询学生记录
	vector<shared_ptr<Student>> query(int flag, string str);

	//清空回收站
	void clear();

	//恢复学生信息记录
	void rollback();

	//=========================以下是课程操作============================
	//添加课程
	void addCourse();

	//打印课程信息
	void printCourses();

	//为学生添加成绩
	void addScores(vector<Student_ptr> stud);

	//=============================虚函数================================
	virtual void setLeftFile(string newFile) {
		cout << "无法在基类中使用setLeftFile()" << endl;
	}
	virtual void setRightFile(string newFile) {
		cout << "无法在基类中使用setRightFile()" << endl;
	}
	virtual void store() { cout << "无法在基类中使用store()" << endl; }
	virtual void read() { cout << "无法在基类中使用read()" << endl; }
	virtual void storeCourses() { cout << "无法在基类中使用storeCourses()" << endl; }
	virtual void readCourses() { cout << "无法在基类中使用readCourses()" << endl; }
	virtual void append(string str) { cout << "无法在基类中使用append()" << endl; }
	virtual ~Base() {}
};

class Manager {
	shared_ptr<Base> base_ptr;
public:
	Manager(shared_ptr<Base> base_ptr) :base_ptr(base_ptr) {}
	void setBase_ptr(shared_ptr<Base> newPtr) {
		this->base_ptr = newPtr;
	}
	//=================================Manager接口函数========================================
	//添加学生记录
	void add();

	//打印学生信息记录
	void print() {
		base_ptr->print();
		cout << "\n已返回到主菜单" << endl;
	}

	//读取文件中学生信息
	void read();

	//存储当前学生信息记录到文件中
	void store();

	//将学生的标记位设为1，表示逻辑删除
	void remove();

	//恢复被删除学生记录
	void rollback();

	//查询操作，flag为1表示按学号查询，为2表示按姓名查询，为3表示按名次查询
	void query();

	//修改学生信息
	void revise();

	//对list元素排序，flag为1表示按num排序，2表示按姓名排序，3表示按名次排序；bl为0表示降序，为1表示升序
	void sort();

	//清空内存中的学生信息记录
	void clear();			

	//添加课程信息
	void addCourse();

	//打印当前课程信息
	void printCourses();

	//读取文件中课程信息
	void readCourses(); 

	//存储当前课程信息记录到文件中
	void storeCourses();

	//为学生添加课程成绩
	void addScores();

	//实现多文件连续追加到同一个文件操作
	void filesAppend();
};


class UnaryFile : public Base {
	friend class Manager;
protected:
	string leftFile;	//保存左文件名
	string courseFile;	//保存课程文件名
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
	
	//存储学生信息记录文件
	virtual void store() override;		

	//读取学生信息记录文件
	virtual void read() override;

	//设置要读取的文件
	virtual void setLeftFile(string newFile) override {
		this->leftFile = newFile;
	}
	//设置要追加到的文件（子子类定义）
	virtual void setRightFile(string newFile) override {
		cout << "无法在基类中使用setRightFile()" << endl;
	}

	//存储课程信息记录文件
	virtual void storeCourses() override;

	//读取课程信息记录文件
	virtual void readCourses() override;

	//多文件追加操作（子子类定义）
	virtual void append(string str) override { cout << "无法在基类中使用append()" << endl; }
};
class BinaryFile : public UnaryFile {
	friend class Manager;
	vector<string> studentFiles;
	string rightFile;	//保存右文件名
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
	virtual void append(string str) override;		//将左文件记录追加到右文件末尾
};
#endif // !MANAGER_H

