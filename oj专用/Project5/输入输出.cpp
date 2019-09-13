#include<iostream>

class Rectangle {

private:
	int height;
	int width;
public:
	Rectangle(int i1, int i2): height(i1),width(i2) { }
	int get_area() {
		return height * width;
	}
};

using namespace std;

int main() {

	int height1, width1, height2, width2;
	cin >> height1 >> width1 >> height2 >> width2;
	Rectangle r1 = Rectangle(height1, width1), r2 = Rectangle(height2, width2);
	cout << r1.get_area() << '\n' << r2.get_area() << endl;
	return 0;
}