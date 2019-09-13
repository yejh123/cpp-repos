#include <iostream>
#include <string>
using namespace std;

//* ���ύ���´��� *//
template <typename T> class Array {
	/*  ����Array��  */
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
//* ���ύ���ϴ��� *//

int main()
{
	int n;
	while (cin >> n)//��������Ԫ�ظ���n
	{
		//����n��int������
		Array<int> a_int(n);
		int number;
		for (int i = 0; i < n; i++)
		{
			cin >> number;
			a_int.set(number, i);
		}
		cout << a_int.getMax() << endl;

		//����n��double������
		Array<double> a_dou(n);
		double d;
		for (int i = 0; i < n; i++)
		{
			cin >> d;
			a_dou.set(d, i);
		}
		cout << a_dou.getMax() << endl;

		//����n��char������
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