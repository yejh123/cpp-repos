#include<iostream>
using namespace std;
template<typename T> class Array {
	T *arr;
	int size;
	int foot;
public:
	Array(int size) :size(size), arr(new T[size]), foot(0) {}
	void add(T t) {
		arr[this->foot++] = t;
	}
	Array operator+(const Array &a) {
		Array result(this->size);
		for (int i = 0; i < this->size; ++i) {
			result.add(this->arr[i] + a.arr[i]);
		}
		return result;
	}
	Array operator-(const Array &a) {
		Array result(this->size);
		for (int i = 0; i < this->size; ++i) {
			result.add(this->arr[i] - a.arr[i]);
		}
		return result;
	}
	ostream& print() {
		for (int i = 0; i < this->size; ++i) {
			cout << this->arr[i] << " ";
		}
		return cout;
	}
};
int main() {
	int i1, i2;
	while (cin >> i1 >> i2) {
		Array<int> arr1(i1), arr2(i1);
		Array<double> arr3(i2), arr4(i2);
		for (int i = 0; i < i1; ++i) {
			int t;
			cin >> t;
			arr1.add(t);
		}
		for (int i = 0; i < i1; ++i) {
			int t;
			cin >> t;
			arr2.add(t);
		}
		for (int i = 0; i < i2; ++i) {
			double t;
			cin >> t;
			arr3.add(t);
		}
		for (int i = 0; i < i2; ++i) {
			double t;
			cin >> t;
			arr4.add(t);
		}
		Array<int> result1 = arr1 + arr2;
		Array<int> result2 = arr1 - arr2;
		Array<double> result3 = arr3 + arr4;
		Array<double> result4 = arr3 - arr4;
		cout << "intadd:";
		result1.print();
		cout << "intsub:";
		result2.print();
		cout << "\ndoubleadd:";
		result3.print();
		cout << "doublesub:";
		result4.print();
		cout << endl;
	}
}
/*
2 3 
10 9 5 6
6.5 7.8 5.4 1.2 2.3 4.5
4 4 
11 12 13 14 3 4 5 6
11.22 23.45 34.67 11.45 14.55 2.33 8.99 10.01
*/