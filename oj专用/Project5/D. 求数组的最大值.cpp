#include <iostream>
#include <string>
using namespace std;

//* 仅提交以下代码 *//
template <typename T> class Array {
	/*  完善Array类  */
private:
	unsigned size;
	T* a;
public:
	Array(int n) :size(n), a(new T[size]) {}
	void set(T t, int i) {
		a[i] = t;
	}
	T getMax() {
		T t = a[0];
		for (int i = 1; i < size; ++i) {
			if (a[i] > t)
				t = a[i];
		}
		return t;
	}
};
//* 仅提交以上代码 *//

int main()
{
	int n;
	while (cin >> n)//输入数组元素个数n
	{
		//测试n个int型数据
		Array<int> a_int(n);
		int number;
		for (int i = 0; i < n; i++)
		{
			cin >> number;
			a_int.set(number, i);
		}
		cout << a_int.getMax() << endl;

		//测试n个double型数据
		Array<double> a_dou(n);
		double d;
		for (int i = 0; i < n; i++)
		{
			cin >> d;
			a_dou.set(d, i);
		}
		cout << a_dou.getMax() << endl;

		//测试n个char型数据
		Array<char> a_char(n);
		char c;
		for (int i = 0; i < n; i++)
		{
			cin >> c;
			a_char.set(c, i);
		}
		cout << a_char.getMax() << endl;
	}

	return 0;
}