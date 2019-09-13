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
		istringstream ist(a);         //a保存一行
		string word;
		while (ist >> word)           //从ist读入一词
			cout << word << " ";
		cout << endl;                 //一行输出完成
	}
	return 0;
}