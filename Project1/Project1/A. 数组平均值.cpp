#include <iostream>
#include <iomanip>
using namespace std;
template<typename T> T average(T *arr, int size) {
	T result = 0;

	for (int i = 0; i < size; ++i) {
		result += arr[i];
	}
	return result / size;
}
int main() {
	int i1, i2;
	while (cin >> i1 >> i2) {
		int *arr1 = new int[i1];
		double *arr2 = new double[i2];
		for (int i = 0; i < i1; ++i) {
			int t;
			cin >> t;
			arr1[i] = t;
		}
		for (int i = 0; i < i2; ++i) {
			double t;
			cin >> t;
			arr2[i] = t;
		}
		int a[5] = { 1,2,5,9,8 };
		cout << "Average of array(int):" << average(arr1, i1) << endl;
		cout <<fixed<<setprecision(2)<< "Average of array(double):" << average(arr2, i2) << endl;
	}
}