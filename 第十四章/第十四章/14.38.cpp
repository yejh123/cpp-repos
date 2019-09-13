#include <string>
#include <iostream>
#include <fstream>
using namespace std;
struct check_word {
private :
	size_t size ;
public:
	check_word(size_t t):size(t) { }
	size_t operator() (istream &is){
		string word;
		size_t n = 0;
		while (is >> word) {
			if (word.size() == size)
				++n;
		}
		return n;
	}
};
int main() {
	for (int i = 1; i != 11; ++i) {
		ifstream in("data.txt");
		check_word cw(i);
		auto n = cw(in);
		cout << "长度为"<<i<<"的单词有" << n << "个" << endl;
	}
}