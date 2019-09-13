#pragma once

#ifndef EXCEPTION.H
#define EXCEPTION.H
#include "Sales_data.h"
class isbn_mismatch : public logic_error
{
private:
	const string left, right;
public:
	explicit isbn_mismatch(const string& s) : logic_error(s) {}
	isbn_mismatch(const string& s, const string& lhs, const string& rhs) : logic_error(s) , left(lhs), right(rhs){}
	virtual char const* what() const override
	{
		string s = logic_error::what() + string("one is ") + left + string("the other is ") + right;
		return s.c_str();
	}
};
#endif // !EXCEPTION.H
