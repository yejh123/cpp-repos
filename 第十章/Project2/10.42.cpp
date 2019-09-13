#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;
void eliminate(list<string> &li)
{
	for_each(li.cbegin(), li.cend(), [](const string &s) {cout << s << " "; });
	cout << li.size() << endl;
	li.sort();                //sort(li.begin(), li.end());
	li.unique();          //auto it = unique(li.begin(), li.end());
	for_each(li.cbegin(), li.cend(), [](const string &s) {cout << s << " "; });
	cout << li.size() << endl;

}
int main() {
	list <string> ls{ "abv","fhi","jfskl","fhi","fdhja","fad","abv","dafg","jfskl" };
	eliminate(ls);
}