#include "Chapter10.h"
bool isShorter(const string & s1, const string &s2) {
	return s1.size() < s2.size();
}
void binary_test() {
	ifstream in("Text.txt");
	if (!in) {
		cerr << "文件不存在";
		return;
	}
	string line;
	getline(in, line);
	istringstream is(line);
	string s;
	vector<string> vec;
	while (is >> s) {
		vec.push_back(s);
	}
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
	stable_sort(vec.begin(), vec.end(), isShorter);			//运用稳定排序
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
}

bool compare_as_ints(double i, double j)
{
	return (int(i) < int(j));
}

void binary_test2() {
	double mydoubles[] = { 3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58 };

	std::vector<double> myvector;

	myvector.assign(mydoubles, mydoubles + 8);

	std::cout << "using default comparison:";
	std::stable_sort(myvector.begin(), myvector.end());
	for (std::vector<double>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	myvector.assign(mydoubles, mydoubles + 8);

	std::cout << "using 'compare_as_ints' :";
	std::stable_sort(myvector.begin(), myvector.end(), compare_as_ints);
	for (std::vector<double>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}