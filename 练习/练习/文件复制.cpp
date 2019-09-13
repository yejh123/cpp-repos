#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
/**
 * 拷贝文件
 * @param src 原文件
 * @param des 目标文件
 * @return ture 拷贝成功, false 拷贝失败
 */
bool CopyFile(const char *src, const char *des)
{
	FILE * fSrc;
	int err1 = fopen_s(&fSrc, src, "rb");
	if (err1)
	{
		printf("打开文件`%s`失败", src);
		return false;
	}
	FILE * fDes;
	int err2 = fopen_s(&fDes, des, "wb");
	if (err2)
	{
		printf("创建文件`%s`失败", des);
		return false;
	}

	unsigned char * buf;
	unsigned int length;
	fseek(fSrc, 0, SEEK_END);
	length = ftell(fSrc);
	buf = new unsigned char[length + 1];
	memset(buf, 0, length + 1);
	fseek(fSrc, 0, SEEK_SET);
	fread(buf, length, 1, fSrc);

	fwrite(buf, length, 1, fDes);

	fclose(fSrc);
	fclose(fDes);
	delete[] buf;
	return true;
}

void CopyFile2(const char *src, const char *des) {
	ifstream in(src, ios::binary);
	ofstream out(des, ios::binary);
	if (!in) {
		cout << "打开文件失败" << endl;
		return;
	}
	if (!out) {
		cout << "创建文件失败" << endl;
		return;
	}
	//out << in.rdbuf();
	char c[1024] = { 0 };
	while (in.read(c, sizeof(char) * 1024)) {
		out.write(c, sizeof(char) * 1024);
	}
	out.write(c, in.gcount());				//必须要加上这一行,否则文件会缺少1K数据
	in.close();
	out.close();
	cout << "复制成功" << endl;
}
int main()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d-%02d-%02d  %02d:%02d:%02d  星期%d", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wDayOfWeek);
}
