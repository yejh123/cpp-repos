#pragma once

#include "TextQuery.h"
#include <algorithm>
#include <iterator>

//Query_base 类
class Query_base
{
	friend class Query;
private:
	virtual string rep() const = 0;
	virtual QueryResult eval(Textquery &text) const = 0;
protected:
	//	virtual ~Query_base() = default;
};

class Query
{
	friend Query operator~ (const Query &);
	friend Query operator| (const Query &, const Query &);
	friend Query operator& (const Query &, const Query &);
private:
	shared_ptr<Query_base> q;
	//私有构造函数
	Query(shared_ptr<Query_base> sq) :q(sq) { }
public:
	//公有构造函数
	Query(const string &s);

	QueryResult eval(Textquery &text) const
	{
		return q->eval(text);
	}
	string rep()const
	{
		return q->rep();
	}
};
/*
//WordQuery 类
class WordQuery :public Query_base
{
	friend class Query;
private:
	string query_word;
	virtual string rep() const override
	{
		return query_word;
	}
	virtual QueryResult eval(Textquery &text) const {
		return text.query(query_word);
	}
	//构造函数
	WordQuery(const string &s) :query_word(s) { }
};
//Query(const string &s) 构造函数
Query::Query(const string &s) :q(shared_ptr<Query_base>(new WordQuery(s))) { }

//NotQuery 类
class NotQuery :public Query_base
{
	friend class Query;
	friend Query operator~(const Query &q);
private:
	Query query;
	//构造函数
	NotQuery(const Query &q) :query(q) { }
	virtual string rep() const override {
		return "~(" + query.rep() + ")";
	}
	virtual QueryResult eval(Textquery &text) const override;
};
Query operator~ (const Query &q){
	NotQuery nq(q);
	return make_shared<Query_base>(nq);
}
QueryResult NotQuery::eval(Textquery &text) const
{
	QueryResult q = query.eval(text);
	auto total_lines = q.get_file();
	shared_ptr<set<int>> lines = make_shared<set<int>>();
	set_difference(total_lines->begin(), total_lines->end(), q.begin(), q.end(), inserter(*total_lines, total_lines->begin()));
	return QueryResult(rep(), q.get_file(), lines);
}

//BinaryQuery 类
class BinaryQuery :public Query_base
{
	//友元待定
protected:
	Query lhs;
	Query rhs;
	string opsym;
	//构造函数
	BinaryQuery(const Query &l, const Query &r) :lhs(l), rhs(r) { }
	virtual string rep() const override
	{
		return "(" + lhs.rep() + opsym + rhs.rep() + ")";
	}
};
//AndQuery 类
class AndQuery :public BinaryQuery
{
	friend Query operator& (const Query &lhs, const Query &rhs);
private:
	virtual QueryResult eval(Textquery &text) const override;
//构造函数
	AndQuery(const Query &l, const Query &r) :BinaryQuery(l, r) { }
};
Query operator& (const Query &lhs, const Query &rhs) {
	AndQuery aq(lhs, rhs);
	return make_shared<Query_base>(aq);
}
QueryResult AndQuery::eval(Textquery &text) const
{
	QueryResult l = lhs.eval(text), r = rhs.eval(text);
	shared_ptr<set<int>> lines = make_shared<set<int>>();
	set_intersection(l.begin(), l.end(), r.begin(), r.end(), inserter(*lines, lines->begin()));
	return QueryResult(rep(), l.get_file(), lines);
}

//OrQuery 类
class OrQuery :public BinaryQuery
{
	friend Query operator| (const Query &lhs, const Query &rhs);
private:
	virtual QueryResult eval(Textquery &text) const override;
//构造函数
	OrQuery(const Query &l, const Query &r) :BinaryQuery(l, r) { }
};
Query operator| (const Query &lhs, const Query &rhs) {
	OrQuery oq(lhs, rhs);
	return make_shared<Query_base>(oq);
}
QueryResult OrQuery::eval(Textquery &text) const
{
	QueryResult l = lhs.eval(text), r = rhs.eval(text);
	shared_ptr<set<int>> lines = make_shared<set<int>>();
	lines->insert(r.begin(), l.end());
	return QueryResult(rep(), l.get_file(), lines);
}

*/