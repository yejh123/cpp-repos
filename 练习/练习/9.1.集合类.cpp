#include <iostream>
using namespace std;
int main() {
	int radius, height;
	cin >> radius >> height;
	cout << 4 * radius * radius * radius << " " << 12 * radius * radius << " " << 3 * radius * radius * height << " " << 6 * radius * radius + 6 * radius * height <<" "<< endl;
}