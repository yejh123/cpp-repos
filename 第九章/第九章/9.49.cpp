#include <iostream>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("data");
	string word,longest;
	while (in >> word) {
		unsigned pos = 0;
		cout << word << " ";
		if ((pos = word.find_first_of("bdfghjklpqty", pos)) == string::npos) {
                if (longest.size() < word.size())
				longest = word;
		}

	}
	cout << longest << endl;
}