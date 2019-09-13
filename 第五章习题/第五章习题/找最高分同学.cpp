#include<iostream>
#include<map>
#include<string>
using namespace std;
struct s
{

};
int main()
{
	map<string, int> m;
	string name;
	int score;

		int n = 1;
		while (n <= 10 && cin >> name >> score)
		{
			m[name] = score;
			++n;
		}
		int highest = 0;
		string highestname;
		map<string, int>::iterator it;
		for (it = m.begin(); it != m.end(); ++it)
		{
			if (highest < it->second)
			{
				highestname = it->first;
				highest = it->second;
			}
		}
		cout << highestname << endl;
	
	
}