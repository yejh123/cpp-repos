#include <string>
#include <iostream>
#include <fstream>
using namespace std;
struct check_word {
private:
	size_t size;
public:
	check_word(size_t t) :size(t) { }
	size_t operator() (istream &is) {
		string word;
		size_t n = 0;
		while (is >> word) {
			if (word.size() <= size)
				++n;
		}
		return n;
	}
};
int main() {
	ifstream in("data.txt");
	check_word cw(9);
	auto n = cw(in);
		cout << "长度在1至9的单词有" << n << "个" << endl;
	}
}