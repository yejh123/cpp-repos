#include <iostream>
#include <string>
using namespace std;
/*
假设某销售公司有一般员工、销售员工和销售经理。月工资的计算办法是:
一般员工月薪=基本工资；
销售员工月薪=基本工资+销售额*提成率；
销售经理月薪=基本工资+岗位工资+销售额*提成率。
编写程序，定义一个表示一般员工的基类Employee,它包含3个表示员工基本信息的数据成员：编号number、姓名name和基本工资basicSalary;
由Employee类派生销售员工Salesman类,Salesman类包含两个新数据成员：销售额sales和静态数据成员提成比例commrate;
再由Salesman类派生表示销售经理的Salesmanager类,Salesmanager类包含新数据成员：岗位工资jobSalary。
为这些类定义初始化数据的构造函数,以及输入数据input、计算工资pay和输出工资条print的成员函数。
设公司员工的基本工资是2000元，销售经理的岗位工资是3000元，提成比例=5/1000。
在main函数中，输入若干个不同类型的员工信息,测试你的类结构。

输入
第一行：基本员工编号 姓名
第二行：销售员工编号 姓名 销售额
第三行：销售经理编号 姓名 销售额

输出
普通员工的： 姓名 编号 月薪
销售员工的： 姓名 编号 月薪
销售经理的： 姓名 编号 月薪

样例输入
1 aaa
2 bbb 500
3 ccc 5000
样例输出
aaa 1 2000
bbb 2 2002.5
ccc 3 5025
*/
class Employee {

};
int main() {
	int n1, n2, n3;
	string s1, s2, s3;
	double d2, d3;
	cin >> n1 >> s1;
	cin >> n2 >> s2 >> d2;
	cin >> n3 >> s3 >> d3;
	cout << s1 << " " << n1 << " " << 2000 << endl;
	cout << s2 << " " << n2 << " " << 2000 + d2 * 0.005 << endl;
	cout << s3 << " " << n3 << " " << 5000 + d3 * 0.005 << endl;
}