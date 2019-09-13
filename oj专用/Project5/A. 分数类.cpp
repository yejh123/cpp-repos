#include<iostream>
#include <cmath>
using namespace std;
class Fraction {
	// 在此处补充你的代码
	int a1;
	int a2;
public:
	Fraction(int i1, int i2) {
		int bl = 1;
		if (i1 < 0) {
			i1 = -i1;
			bl *= -1;
		}
		if (i2 < 0) {
			i2 = -i2;
			bl *= -1;
		}
		int max = 1;
		int t = i1 > i2 ? i1 : i2;
		for (int i = 2; i <=  2 * sqrt(t); i++) {
			if (i1 % i == 0 && i2 % i == 0)
				max = i;
		}
		if (max != 1) {
			i1 = i1 / max;
			i2 = i2 / max;
		}

		this->a1 = i1 * bl;
		this->a2 = i2;

	}
	void print() {
		cout << this->a1 << "/" << this->a2 << endl;
	}
};
int main() {
	int numerator, denominator;
	while (cin >> numerator >> denominator)
	{
		Fraction myFraction(numerator, denominator);
		myFraction.print();
	}
	return 0;
}