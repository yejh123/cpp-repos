#include "TextQuery.h"

void runqueries(ifstream &infile)
{
	Textquery tq(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit:";
		string s;
		if (!(cin >> s)  || s == "q")
			break;
		print(cout, tq.query(s));
	}
}
int main()
{
	ifstream in("data.txt");
	runqueries(in);
}