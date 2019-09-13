#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{
	map<string, int> m{ {"das",1},{"fas",2} };
	map<string, int>::const_iterator it = m.cbegin();
	//pair<string,int>::iterator it1 = m.being()            ´íÎóÉùÃ÷
	++it;             //itÈÔÄÜµİÔö?!
	cout << it->first << " " << it->second << endl;
}