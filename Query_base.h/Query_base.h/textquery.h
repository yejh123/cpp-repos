
#ifndef _TEXTQUERY_H
#define _TEXTQUERY_H

#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

class QueryResult;	//查询结果类
class TextQuery;	//文本查询类

using line_no = std::vector<std::string>::size_type;

//查询结果类
class QueryResult
{
	friend class TextQuery;
	friend std::ostream &operator<<(std::ostream &os, const QueryResult &q);

public:
	QueryResult() = default;

	QueryResult(std::string q_word, std::shared_ptr<std::set<line_no>> lines,
		std::shared_ptr<std::vector<std::string>> word_file) :
		q_word_(q_word), lines_(lines), word_file_(word_file) {}

	std::set<line_no>::iterator begin();

	std::set<line_no>::iterator end();

	std::shared_ptr<std::vector<std::string>> get_file();

private:
	std::string q_word_;										//要查询的单词
	std::shared_ptr<std::set<line_no>> lines_;					//出现行号的集合
	std::shared_ptr<std::vector<std::string>> word_file_;		//单词文件
};


//文本查询类
class TextQuery
{
	friend class QueryResult;

public:
	TextQuery() = default;

	TextQuery(std::ifstream &is);

	//查询函数
	QueryResult query(const std::string &word) const;

private:
	std::shared_ptr<std::vector<std::string>> m_file_;	//查询的文本
	std::map<std::string, std::shared_ptr<std::set<line_no>>> m_word_line_;	//每个单词以及它的行号集合
};


//Query_base抽象基类，制定一个标准
class Query_base
{
	friend class Query;

protected:
	virtual ~Query_base() = default;

private:
	//eval返回与当前TextQuery匹配的QueryResult
	virtual QueryResult eval(const TextQuery &) const = 0;
	//rep表示查询的一个string
	virtual std::string rep() const = 0;
};


//接口类，基类包括派生类都可以通过Query来使用，隐藏实现
//Query包装了Query_base
class Query
{
	friend Query operator~(const Query &);					//非
	friend Query operator&(const Query &, const Query &);	//与
	friend Query operator|(const Query &, const Query &);	//或
	friend std::ostream &operator<<(std::ostream &os, const Query &query);

public:
	Query(const std::string &query_word);

	QueryResult eval(const TextQuery &t) const
	{
		return query_->eval(t);
	}

	std::string rep() const
	{
		return query_->rep();
	}

private:
	//构造函数定义为private,不希望一般用户随便定义Query_base对象。 
	//注意：友元类可以访问protected和private成员。
	Query(std::shared_ptr<Query_base> query) : query_(query) {}

	//通过智能指针实现动态绑定
	std::shared_ptr<Query_base> query_;	//查询
};


//派生类
class WordQuery : public Query_base
{
	friend class Query;

	WordQuery(const std::string &query_word) : query_word_(query_word) {}

	//查询单词
	QueryResult eval(const TextQuery &t) const
	{
		return t.query(query_word_);
	}

	//查询的一个string
	std::string rep() const
	{
		return query_word_;
	}

private:
	std::string query_word_;	//要查找的单词	
};

//无论哪种查询都是建立在WordQuery的根本上，因此 Query的构造函数用一个WordQuery来初始化  
inline Query::Query(const std::string &query_word) :
	query_(new WordQuery(query_word)) {}


//非查询类
class NotQuery : public Query_base
{
	friend Query operator~(const Query &query);

	NotQuery(const Query &query) : query_(query) {}

	//覆盖纯虚函数
	QueryResult eval(const TextQuery &) const override;

	std::string rep() const override
	{
		return "~(" + query_.rep() + ")";
	}

private:
	Query query_;	//查询对象
};

inline Query operator~(const Query &query)
{
	return std::shared_ptr<Query_base>(new NotQuery(query));
}


//两个运算符的抽象基类  
class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &left, const Query &right, std::string op) :
		left_(left), right_(right), op_(op) {}

	std::string rep() const override
	{
		return "(" + left_.rep() + " " + op_ + right_.rep() + ")";
	}

	//因为eval函数还没有定义，所以BinaryQuery还是抽象类

	Query left_;			//左操作数
	Query right_;			//右操作数
	std::string op_;		//操作符
};


//与操作类
class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query &left, const Query &right);

	AndQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "&") {}

	QueryResult eval(const TextQuery &t) const;
};

inline Query operator&(const Query &left, const Query &right)
{
	return std::shared_ptr<Query_base>(new AndQuery(left, right));
}


//或操作类
class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query &left, const Query &right);

	OrQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "|") {}

	QueryResult eval(const TextQuery &t) const;
};

inline Query operator|(const Query &left, const Query &right)
{
	return std::shared_ptr<Query_base>(new OrQuery(left, right));
}

#endif
