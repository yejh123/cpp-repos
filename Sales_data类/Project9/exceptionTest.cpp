
#include "Sales_data.h"
int main()
{
	Sales_data sd1("a001", 59, 16.9), sd2("a002", 66, 18);
	try {
		cout << (sd1 + sd2) << endl;
	}
	catch (const isbn_mismatch& e)
	{
		cout << e.print() << endl;
	}
}