/*
以表格形式输出：当x = 1°到n°时sinx、cosx和tanx的值。要求：输出时，第一列数据宽度为3，其他数据的宽度为10，左对齐，保留小数点后5位。p_i = 3.14159265
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
	const double PER = 3.14159265 / 180;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cout << left << setw(3) << i << setw(10) << fixed << setprecision(5) << sin(i * PER) << setw(10) << cos(i * PER) << tan(i * PER) << endl;
	}
}