#include "Bulk_quote.h"
#include "Quote.h"
using namespace std;
int main() {
	Quote q("1-21", 10);
	Bulk_quote bq("1-99",12, 5, 0.1);
	q.debug();
	bq.debug();

 }