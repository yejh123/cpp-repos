#include <iostream>
#include <string>
using namespace std;
int main() {
	string s1, s2, s3, s4;
	int  i[4];
	int d[4];
	int sl[4];
	cin >> s1 >> i[0] >> d[0] >> s2 >> i[1] >> d[1] >> s3 >> i[2] >> d[2] >> s4 >> i[3] >> d[3];
	for (int t = 0; t < 4; ++t) {
		if (i[t] == 1) {
			sl[t] = 2000 + 50 * d[t];
		}
		else if (i[t] == 2) {
			sl[t] = 2000 + 30 * d[t];
		}
		else if (i[t] == 3) {
			sl[t] = 2000 + 20 * d[t];
		}
	}
	int max = 0, min = 9999, sum = 0;
	for (int t = 0; t < 4; ++t) {
		if (sl[t] > max)
			max = sl[t];
		if (sl[t] < min)
			min = sl[t];
		sum += sl[t];
	}
	cout << sum << '\n' << (double)sum / 4 << '\n' << max << "\n" << min << endl;
}