//���ʲ�ѯ 2018.9.2
#pragma once
#ifndef TXETQUERY_H
#define TEXTQUERY_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
using namespace std;
struct QueryResult;
struct Textquery
{
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<int>>> m;

public:
	//���캯��
	Textquery(ifstream &ifs):file(new vector<string>)
	{
		string line, word;
		int ln = 0;
		while (getline(ifs, line)) {
			file->push_back(line);    
			istringstream is (line);
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
	friend void print(ostream &os, QueryResult qr);
private:
	string sought;
	shared_ptr<vector<string>> file;
	shared_ptr<set<int>> lines;
	

public:
	//���캯��
	QueryResult(string s,shared_ptr<vector<string>> svs, shared_ptr<set<int>> ssi) :sought(s),file(svs), lines(ssi) {}
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
		return QueryResult(s, file,nodata);
	else
		return QueryResult(s,  file,loc->second);
}


void print(ostream &os, QueryResult qr)
{
	os << qr.sought << "������"<< qr.lines->size() << "��" << endl;
	
	for (auto n : *qr.lines)
	{
		cout << "(line" << n + 1 << ")" << " " << (*qr.file)[n] << endl;
	}
}
#endif // !TXETQUERY_H
