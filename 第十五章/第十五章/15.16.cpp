#include "Bulk_quote.h"
using namespace std;
int main() {
	//Disc_quote d("0-1-2", 12.50, 10, 0.1);       ������ʹ�ó������Ķ���
	Bulk_quote bq("0-45", 12.50, 10, 0.1);
	print_total(bq,20);

}