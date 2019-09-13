
#include "textquery.h"
#include <iterator>

//QueryResult
std::ostream &operator<<(std::ostream &os, const QueryResult &result)
{
	os << "单词出现了:" << result.lines_->size() << "次\n";
	for (line_no i : *result.lines_)
	{
		os << "  " << "line(" << i + 1 << ") ";
		os << (*(result.word_file_))[i] << "\n";
	}
	return os;
}


std::set<line_no>::iterator QueryResult::begin()
{
	return lines_->begin();
}

std::set<line_no>::iterator QueryResult::end()
{
	return lines_->end();
}

std::shared_ptr<std::vector<std::string>> QueryResult::get_file()
{
	return word_file_;
}



//TextQuery
//构造函数
TextQuery::TextQuery(std::ifstream &is) : m_file_(new std::vector<std::string>)
{
	std::string word;	//单词
	std::string line;	//一行文本
	static int i = 0;	//行号

	while (std::getline(is, line))
	{
		m_file_->push_back(line);	//存入vactor<string>的末尾
		i = m_file_->size() - 1;	//最后一行的行号
		std::istringstream ist(line);
		while (ist >> word)
		{
			auto &li = m_word_line_[word];	//单词word所在的行号集
			if (!li)
			{
				//为空，创建一个set<line_no>
				li.reset(new std::set<line_no>);
			}
			//不为空
			li->insert(i);
		}
	}
}

//单词查询
QueryResult TextQuery::query(const std::string &word) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);	//指向行号集的指针
	auto ret = m_word_line_.find(word);
	if (ret == m_word_line_.end())
	{
		return QueryResult(word, nodata, m_file_);
	}
	else
	{
		return QueryResult(word, ret->second, m_file_);
	}
}

std::ostream &operator<<(std::ostream &os, const Query &query)
{
	return os << query.rep();
}


//NotQuery
QueryResult NotQuery::eval(const TextQuery &text) const
{
	auto result = query_.eval(text);	//文本查询的结果集合
	auto ret_lines = std::make_shared<std::set<line_no>>();	//行号集合
	auto begin = result.begin();
	auto end = result.end();
	auto sz = result.get_file()->size();	//文本总行数

	for (std::size_t n = 0; n != sz; ++n)
	{
		if (begin == end || *begin != n)
		{
			ret_lines->insert(n);
		}
		else if (begin != end)
		{
			++begin;
		}
	}

	return QueryResult(rep(), ret_lines, result.get_file());
}


//AndQuery
QueryResult AndQuery::eval(const TextQuery &text) const
{
	auto left = left_.eval(text);
	auto right = right_.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	//将两个范围的交集写入一个目的迭代器中
	//本次调用的目的迭代器向ret_lines添加元素
	set_intersection(left.begin(), left.end(),
		right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));

	return QueryResult(rep(), ret_lines, left.get_file());
}


//OrQuery
QueryResult OrQuery::eval(const TextQuery &text) const
{
	auto left = left_.eval(text);
	auto right = right_.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());

	return QueryResult(rep(), ret_lines, left.get_file());
}
