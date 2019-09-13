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
		cout << "������һֱ��Ӷ���ѧ����¼����0���˳�" << endl;

		string subjectName, teacherName;
		double credit;
		while (1) {
			cout << "\n����������γ̵����ơ��ον������֡��γ�ѧ��(��0���˳�):" << endl;
			cout << "Demand>";
			cin >> subjectName;
			if (subjectName == "0") {
				cout << "\n�ѷ��ص����˵�����Ҫ�鿴�γ̼�¼�밴11" << endl;
				break;
			}
			cin >> teacherName >> credit;
			if (!cin) {
				cout << "\nѧ��ֻ����������! \n���ѧ����¼ʧ�ܣ��ѷ��ص����˵�!" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return 0;
			}
			string str1, str2;
			Date beg, end;

			cout << "\n������γ̵���ʼʱ�䣬����2018-03-01(��0��ʾ����Ĭ����ʼʱ��):" << endl;
			cout << "Demand>";
			cin >> str1;
			regex r("([\\d]{4})-([\\d]{1,2})-([\\d]{1,2}\\b)");
			smatch result;
			if (str1 != "0") {
				while (!regex_match(str1, result, r)) {
					cout << "\n���������������������룬����2019-03-01(��0��ʾ����Ĭ����ʼʱ��):" << endl;
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
