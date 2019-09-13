#include <iostream>
#include <string>
#include <vector>
struct ReadString {
private:
	std::istream &is;
public:
	ReadString(std::istream &is = std::cin) : is(is) { }
	std::string operator() (std::istream &is = std::cin) {
		std::string s;
		getline(std::cin, s);
		return s;
	}
};
int main() {
	ReadString ps;
	std::string s;
	std::vector<std::string> vs;
	while (std::cin) {
		s = ps();
		vs.push_back(s);
	}
	for (auto a : vs)
		std::cout << a << std::endl;
}