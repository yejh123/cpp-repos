#include "HasPtr.h"
using namespace std;
int main() {
	HasPtr hp1("asf"),hp2("fhuio"),hp3,hp4;
	hp3 = hp1;
	hp4 =  (std::move(hp2));
}