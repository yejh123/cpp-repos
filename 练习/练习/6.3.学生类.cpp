/*
����һ��Student�࣬�ڸ��ඨ���а�����һ�����ݳ�Ա������score����������̬���ݳ�Ա���ܷ�total��ѧ������count����
��Ա����scoretotalcount(int s)�������÷��������ֺܷ��ۼ�ѧ����������̬��Ա����sum()���ڷ����ܷ֣���̬��Ա����average()������ƽ��ֵ��
��main�����У�����ĳ��ͬѧ�ĳɼ�������������������ȫ��ѧ�����ֺܷ�ƽ���֡�
������������Ŀ��������ͬ��
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