#include "Basket.h"
using namespace std;
int main()
{
	Basket b;
	for (int i = 0; i != 10; ++i) {
		Bulk_quote bq("C++", 30, 10, 0.1);
		b.add_item(bq);
	}
	b.total();
}