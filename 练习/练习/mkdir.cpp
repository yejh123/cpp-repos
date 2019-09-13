#include <io.h>
#include <direct.h>
#include <string>
#include <iostream>
using namespace std;

/*
判断目录是否存在：_access(fileName, 0)，返回值为-1表示不存在，为0表示存在
创建目录：_mkdir(fileName），返回值为-1表示创建失败，为0表示成功
*/
int main(void)
{
	string dir = "./hello";
	if (_access(dir.c_str(), 0) == -1)
	{
		cout << dir << " is not existing" << endl;
		cout << "now make it" << endl;
#ifdef WIN32
		int flag = _mkdir(dir.c_str());
#endif
#ifdef linux 
		int flag = mkdir(dir.c_str(), 0777);
#endif
		if (flag == 0)
		{
			cout << "make successfully" << endl;
		}
		else {
			cout << "make errorly" << endl;
		}
	}

	else if (_access(dir.c_str(), 0) == 0)
	{
		cout << dir << " exists" << endl;
		cout << "now delete it" << endl;
		int flag = _rmdir(dir.c_str());
		if (flag == 0)
		{
			cout << "delete it successfully" << endl;
		}
		else {
			cout << "delete it errorly" << endl;
		}
	}

	//cout<<"Hello World"<<endl;
	cout << "end..." << endl;
	return 0;
}