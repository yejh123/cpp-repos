#include <iostream>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	struct data {
		unsigned year, month, day;
		data(string s) {
			string s1 = s.substr(0,3);
			

			//处理month
			if (s1 == "Jan") {
				month = 1;
			}

			bool bl = 0;
			if (isdigit(s[0])) {
				bl = 1;
				month = stoi(s1);
			}

			//处理day
			//
			if (!bl) {
				string t_day = s.substr(s.find_first_of("0123456789"), 2);
				day = stoi(t_day);
			}
			if (bl) {
				unsigned n1 = s.find("/");
				string t_day = s.substr(n1 + 1, 2);
				day = stoi(t_day);
			}

			//处理year

			string t_year = s.substr(s.size() - 4, 4);
			year = stoi(t_year);

		}
	};

	data d("156/31/1990");
	cout << d.month << " " << d.day << " " << d.year << endl;
}