#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
/**
 * �����ļ�
 * @param src ԭ�ļ�
 * @param des Ŀ���ļ�
 * @return ture �����ɹ�, false ����ʧ��
 */
bool CopyFile(const char *src, const char *des)
{
	FILE * fSrc;
	int err1 = fopen_s(&fSrc, src, "rb");
	if (err1)
	{
		printf("���ļ�`%s`ʧ��", src);
		return false;
	}
	FILE * fDes;
	int err2 = fopen_s(&fDes, des, "wb");
	if (err2)
	{
		printf("�����ļ�`%s`ʧ��", des);
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
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	if (!out) {
		cout << "�����ļ�ʧ��" << endl;
		return;
	}
	//out << in.rdbuf();
	char c[1024] = { 0 };
	while (in.read(c, sizeof(char) * 1024)) {
		out.write(c, sizeof(char) * 1024);
	}
	out.write(c, in.gcount());				//����Ҫ������һ��,�����ļ���ȱ��1K����
	in.close();
	out.close();
	cout << "���Ƴɹ�" << endl;
}
int main()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d-%02d-%02d  %02d:%02d:%02d  ����%d", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wDayOfWeek);
}
