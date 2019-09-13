#include "DebugDelete.h"
#include <string>
#include <memory>
using namespace std;
int main()
{
	unique_ptr<string, DebugDelete> sp1(new string("cnm"), DebugDelete());
	unique_ptr<string, DebugDelete> sp2(new string("cqdq"), DebugDelete());
	sp1.reset(sp2.release());
}