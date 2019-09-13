#pragma once
#ifndef TXETQUERY_H
#define TEXTQUERY_H

#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
using namespace std;

struct QueryResult;	//��ѯ�����
struct TextQuery;	//�ı���ѯ��

struct Textquery
{
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<int>>> m;

public:
	//���캯��
	Textquery(ifstream &ifs) :file(new vector<string>)
	{
		string line, word;
		int ln = 0;
		while (getline(ifs, line)) {
			file->push_back(line);
			istringstream is(line);
			while (is >> word) {
				auto &lines = m[word];
				if (!lines)
					lines.reset(new set<int>);       //reset�Ǳ���ģ�����ָ��lines����Ϊָ���set<int>��ָ��
				lines->insert(ln);
			}
			++ln;
		}
	}
	QueryResult query(const string &s);
};

struct QueryResult
{
	friend ostream &print(ostream &os, QueryResult qr);
private:
	string sought;
	shared_ptr<vector<string>> file;
	shared_ptr<set<int>> lines;


public:
	//���캯��
	QueryResult(string s, shared_ptr<vector<string>> svs, shared_ptr<set<int>> ssi) :sought(s), file(svs), lines(ssi) {}
	//�ӿں���
	set<int>::iterator begin()
	{
		return lines->begin();
	}
	set<int>::iterator end()
	{
		return lines->end();
	}
	shared_ptr<vector<string>> get_file()
	{
		return file;
	}
};

QueryResult Textquery::query(const string &s)
{
	static shared_ptr<set<int>> nodata(new set<int>);
	auto loc = m.find(s);
	if (loc == m.end())
		return QueryResult(s, file, nodata);
	else
		return QueryResult(s, file, loc->second);
}


ostream &print(ostream &os, QueryResult qr)
{
	os << qr.sought << "������" << qr.lines->size() << "��" << endl;

	for (auto n : *qr.lines)
	{
		cout << "(line" << n + 1 << ")" << " " << (*qr.file)[n] << endl;
	}
	return os;
}


//Query_base ������
class Query_base
{
	friend class Query;
private:
	virtual string rep() const = 0;
	virtual QueryResult eval(Textquery &text) const = 0;
protected:
	//virtual ~Query_base() = default;
};

class Query
{
	friend Query operator~ (const Query &);
	friend Query operator| (const Query &, const Query &);
	friend Query operator& (const Query &, const Query &);
	friend std::ostream &operator<<(std::ostream &os, const Query &query);
private:
	shared_ptr<Query_base> q;
	//˽�й��캯��
	Query(shared_ptr<Query_base> sq) :q(sq) { cout << "Query(shared_ptr<Query_base> sq)" << endl; }
public:
	//���й��캯��
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

//WordQuery ��
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
	//���캯��
	WordQuery(const string &s) :query_word(s) { cout << "WordQuery(const string &s)" << endl; }
};
//Query(const string &s) ���캯��
Query::Query(const string &s) :q(new WordQuery(s)) { cout << "Query(const string &s) ���캯��" << endl; }

//NotQuery ��
class NotQuery :public Query_base
{
	friend class Query;
	friend Query operator~(const Query &q);
private:
	Query query;
	//���캯��
	NotQuery(const Query &q) :query(q) { }
	virtual string rep() const override {
		return "~(" + query.rep() + ")";
	}
	virtual QueryResult eval(Textquery &text) const override;
};
Query operator~ (const Query &q){
	return shared_ptr<Query_base>(new NotQuery(q));
}
QueryResult NotQuery::eval(Textquery &text) const
{
	QueryResult q = query.eval(text);
	auto total_lines = q.get_file();
	shared_ptr<set<int>> lines = make_shared<set<int>>();
	set_difference(total_lines->begin(), total_lines->end(), q.begin(), q.end(), inserter(*total_lines, total_lines->begin()));
	return QueryResult(rep(), q.get_file(), lines);
}


//BinaryQuery ��
class BinaryQuery :public Query_base
{
	//��Ԫ����
protected:
	Query lhs;
	Query rhs;
	string opsym;
	//���캯��
	BinaryQuery(const Query &l, const Query &r) :lhs(l), rhs(r) { }
	virtual string rep() const override
	{
		return "(" + lhs.rep() + opsym + rhs.rep() + ")";
	}
};
//AndQuery ��
class AndQuery :public BinaryQuery
{
	friend Query operator& (const Query &lhs, const Query &rhs);
private:
	virtual QueryResult eval(Textquery &text) const override;
	//���캯��
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

//OrQuery ��
class OrQuery :public BinaryQuery
{
	friend Query operator| (const Query &lhs, const Query &rhs);
private:
	virtual QueryResult eval(Textquery &text) const override;
	//���캯��
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

#endif TEXTQUERY_H