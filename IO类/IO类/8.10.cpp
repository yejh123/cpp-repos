#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	ifstream ifs("data");
	vector<string> words;
	string line;
	while (getline(ifs, line)) {
		words.push_back(line);

	}
	
	for (string a: words) {
		istringstream ist(a);         //a����һ��
		string word;
		while (ist >> word)           //��ist����һ��
			cout << word << " ";
		cout << endl;                 //һ��������
	}
	return 0;
}