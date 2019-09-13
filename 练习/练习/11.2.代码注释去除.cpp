#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	vector<string> vec;
	string line;
	bool flag = 0;
	while (getline(cin, line)) {
		if (flag == 0) {
			int index1 = line.find("//");
			int index2 = line.find("/*");
			if (index1 >= 0 && index1 < line.length()) {
				vec.push_back(line.substr(0, index1));
				continue;
			}
			else if (index2 >= 0 && index2 < line.length()) {
				flag = 1;
				continue;
			}
			vec.push_back(line);
			
		}
		if (flag == 1) {
			int index = line.find("*/");
			if (index >= 0 && index < line.length()) {
				flag = 0;
			}
		}
	}
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i]<<endl;
	}

}