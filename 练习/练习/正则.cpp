#include <iostream>
#include <regex>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;
class Date {
	friend ostream& operator<<(ostream& os, const Date& date);
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
ostream& operator<<(ostream& os, const Date& date) {
	os << date.year << "-" << setw(2) << setfill('0') << date.month << "-" << date.day;
	return os;
}
int main() {
	/*queue<int> q;
	q.push(1);
	q.push(2);	
	q.push(3);
	q.push(4);
	q.push(5);
	q.emplace(6);
	q.pop();
	cout << q.front() << endl;
	cout << q.back() << endl;
*/
	try {
		cout << "您可以一直添加多条学生记录，按0可退出" << endl;

		string subjectName, teacherName;
		double credit;
		while (1) {
			cout << "\n请依次输入课程的名称、任课教授名字、课程学分(按0可退出):" << endl;
			cout << "Demand>";
			cin >> subjectName;
			if (subjectName == "0") {
				cout << "\n已返回到主菜单，若要查看课程记录请按11" << endl;
				break;
			}
			cin >> teacherName >> credit;
			if (!cin) {
				cout << "\n学分只能填入数字! \n添加学生记录失败，已返回到主菜单!" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return 0;
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
				cout << (unsigned)stoi(result[1]) << (unsigned)stoi(result[2]) << (unsigned)stoi(result[3]) << endl;
				beg = Date((unsigned)stoi(result[1]), (unsigned)stoi(result[2]), (unsigned)stoi(result[3]));
			}
			else {
				beg = Date(2019, 3, 1);
			}
		}
	}
	catch (regex_error e) {
		cout << e.what() << endl;
	}
}
