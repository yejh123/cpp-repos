#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main() {
	const double Pi = 3.14159265358979323846264338328;
	double t = 0;
	const double b = 0.061;
	for (int i = 0; i < 10; i++) {
		cin >> t;
		cout << "t ตฺ" << i + 1 << "ื้" << sqrt(pow(2 * Pi / t,2) - 2 * b * b)  << endl;
	}
}