#include <iostream>
#include "Bulk_quote.h"
using namespace std;
int main()
{
	Quote q1("0-22-6", 12.50),q2;
	Bulk_quote bq1;
	Bulk_quote bq2("0-45-51", 13, 10, 0.1);
	q2 = q1;
	q2 = std::move(q1);
	bq1 = bq2;
	bq1 = std::move(bq2);
	print_total(q1,20);
}