/*
定义一个Student类，在该类定义中包括：一个数据成员（分数score）及两个静态数据成员（总分total和学生人数count）；
成员函数scoretotalcount(int s)用于设置分数、求总分和累计学生人数；静态成员函数sum()用于返回总分，静态成员函数average()用于求平均值。
在main函数中，输入某班同学的成绩，并调用上述函数求全班学生的总分和平均分。
函数名需与题目中所给相同。
*/
#include <iostream>
#include <string>
using namespace std;
class Student {
	int score;
	static int total;
	static int count;
public:
	void scoretotalcount(int s) {
		this->score = s;
		++count;
		total += s;
	}
	static int sum() {
		return total;
	}
	double average() {
		return (double)total / count;
	}
};
int Student::total = 0;
int Student::count = 0;
int main() {
	for (int i = 0; i < 5; ++i) {
		Student student;
		int s;
		cin >> s;
		student.scoretotalcount(s);
		if (i == 4) {
			cout << student.sum() << " " << student.average() << endl;
		}
	}
}