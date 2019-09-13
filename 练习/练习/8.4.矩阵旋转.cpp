#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int **p = new int*[n + 1];
	for (int i = 0; i < n + 1; ++i) {
		p[i] = new int[n + 1];
	}
	int **p2 = new int*[n + 1];
	for (int i = 0; i < n + 1; ++i) {
		p2[i] = new int[n + 1];
	}
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			int a;
			cin >> a;
			p[i][j] = a;
		}
	}
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			p2[i][j] = p[n + 1 - j][i];
		}
	}
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			cout << p2[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n + 1; ++i) {
		delete[] p[i];
		delete[] p2[i];
	}
	delete[] p;
	delete[] p2;
}