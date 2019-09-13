#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include "Bulk_quote.h"
using namespace std;
struct Basket {
private:
	bool compare(const shared_ptr<Quote> &q1, const shared_ptr<Quote> &q2) {
		return q1->isbn() < q2->isbn();
	}
	multiset < shared_ptr<Quote>> items;
	
public:
	void add_item(const Quote &q) {
		items.insert(q.clone());
	}
	void total() const {
		double sum = 0.0;
		auto iter = items.cbegin();
		for (; iter != items.cend(); iter = items.upper_bound(*iter)) {
			sum += print_total(**iter, items.count(*iter));

		}
		cout << "总价格为:" << sum << endl;
	}
};

