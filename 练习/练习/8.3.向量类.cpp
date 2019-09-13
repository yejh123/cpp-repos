#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* a = new int[n], *b = new int[n];
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		a[i] = t;
	}
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		b[i] = t;
	}
	cout << a[0] + b[0];
	for (int i = 1; i < n; ++i) {
		cout << " " << a[i] + b[i];
	}
	cout << '\n' << a[0] - b[0];
	for (int i = 1; i < n; ++i) {
		cout << " " << a[i] - b[i];
	}
	cout << endl;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i] * b[i];
	}
	cout << sum << endl;
}