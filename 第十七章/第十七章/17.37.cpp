#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cerr << "Usage: execise infile_name" << endl;
		return -1;

	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "Can not open input file" << endl;
		return -1;
	}
	char text[50];
	while (!in.eof())
	{
		in.getline(text, 10);
	
		cout << text ;
		if (!in.good())
		{
			if (in.gcount() == 9)
			{
				in.clear();
			}
			else    //到达文件末尾
				break;
		}
		else
			cout << endl;
	}
}
