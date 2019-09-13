#include <iostream>
#include <iomanip>
using namespace std;
template<typename T> double average(T(&a)[3]) {
	double sum = 0.0;
	for (int i = 0; i < 3; ++i) {
		sum += a[i];
	}
	return sum / 3;
}
int main() {
	int a[3];
	for (int t = 0; t < 3; ++t) {
		cin >> a[t];
	}
	double b[3];
	for (int t = 0; t < 3; ++t) {
		cin >> b[t];
	}
	cout << average(a) << endl;
	cout << fixed << setprecision(3) << average(b) << endl;
}