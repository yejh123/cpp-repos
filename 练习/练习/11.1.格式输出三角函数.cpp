/*
�Ա����ʽ�������x = 1�㵽n��ʱsinx��cosx��tanx��ֵ��Ҫ�����ʱ����һ�����ݿ��Ϊ3���������ݵĿ��Ϊ10������룬����С�����5λ��p_i = 3.14159265
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