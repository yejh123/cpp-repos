#include <iostream>
#include <string>
#include <fstream>
#include "FstreamSales_data.h"
using namespace std;
int main(int argc, char *argv[])
{
	Sales_data total;
	ifstream in(argv[1]);
	ofstream out(argv[2],ofstream::app);
	if (read(in, total)) {
		Sales_data trans;
		while (read(in, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(out, total);
				total = trans;
			}
		}
			print(out, total);
	}
	return 0;
}