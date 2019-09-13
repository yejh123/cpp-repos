
#include "Employee.h"
using namespace std;

	int main()
	{
		Employee e1("sbchang"), e2("hdauoh"),e3(e1);
		cout << e1.get_n() << " " << e2.get_n() <<" "<<e3.get_n()<< endl;
	}

