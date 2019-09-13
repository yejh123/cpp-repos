#include "Bulk_quote.h"
#include "Quote.h"
using namespace std;
int main() {
	Quote q1("0-564-15", 15.25);
	Bulk_quote bq1("0-485-66", 20, 10, 0.1);
	print_total(q1, 20);
	print_total(bq1, 20);

}