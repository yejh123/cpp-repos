#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
struct A {
	int a;
	A(int i) :a(i) { };

};
struct B{
	int b;
	B(int i) :b(i) { };
};
void f(A) {
	
}
void f(B) { }
int main()
{
	f(10);

}