/************************************************************************/
/* 文件说明：
/* 采用分离链接法实现哈希表，采用C++标准库中的vector和list实现
/*
/************************************************************************/
#include <vector>
#include <list>
#include <string>

class Vocabulary;

int hash(const std::string & key, const int &tableSize);
int hash(const int & key, const int &tableSize);
//int hash(const Vocabulary & e, const int &tableSize);

namespace stl
{

	template <typename HashedObj>
	class HashTable
	{
	public:
		//typedef vector<std::list<HashedObj> >::size_type SIZE;

		HashTable(int size = 101);     //初始化哈希表的大小
		~HashTable() {}
		bool contains(const HashedObj & obj);
		bool insert(const HashedObj & obj);
		bool remove(const HashedObj & obj);
	private:

		std::vector<std::list<HashedObj> > theList;   //哈希表
		int myhash(const HashedObj & obj) const;   //哈希函数
	};


	//函数定义
	template <typename HashedObj>
	HashTable<HashedObj>::HashTable(int size /*= 101*/)
	{
		/*根据哈希表的大小分配vector的空间*/
		theList.reserve(size);
		theList.resize(size);
	}

	template <typename HashedObj>
	int HashTable<HashedObj>::myhash(const HashedObj & obj) const
	{
		//根据object不同调用不同版本的hash重载函数
		return hash(obj, theList.size());
	}

	/************************************************************************/
	/* 函数名称：contains
	/* 函数功能：查找指定对象是否在哈希表中
	/* 返回值：存在返回true，不存在返回false
	/************************************************************************/
	template <typename HashedObj>
	bool HashTable<HashedObj>::contains(const HashedObj & obj)
	{
		int iHashValue = myhash(obj);
		const std::list<HashedObj> & tempList = theList[iHashValue];

		std::list<HashedObj>::const_iterator it = tempList.cbegin();

		for (; it != tempList.cend() && *it != obj; ++it);

		if (it != tempList.cend())
			return true;
		else
			return false;
	}

	/************************************************************************/
	/* 函数名称：insert
	/* 函数功能：向hash表中插入元素，如果元素已经存在则返回false，不存在则在链表的最前面插入
	/* 返回值：成功返回true，失败返回返回false
	/************************************************************************/
	template <typename HashedObj>
	bool HashTable<HashedObj>::insert(const HashedObj & obj)
	{
		int iHashValue = myhash(obj);

		std::list<HashedObj> & tempList = theList[iHashValue];
		if (contains(obj))
		{
			return false;   //已经存在返回false
		}

		tempList.push_back(obj);
		return true;
	}

	/************************************************************************/
	/* 函数名称：remove
	/* 函数功能：从哈希表中删除指定元素，如果元素不存在则返回false
	/* 返回值：成功返回true，失败返回返回false
	/************************************************************************/
	template <typename HashedObj>
	bool HashTable<HashedObj>::remove(const HashedObj & obj)
	{
		list<HashedObj> & tempList = theList[myhash(obj)];
		auto it = find(tempList.begin(), tempList.end(), obj);
		if (it == tempList.end())
		{
			return false;
		}
		tempList.erase(it);
		return true;
	}
}


//hash表中存入单词表类，一个对象表示对应一个单词
class Vocabulary
{
public:
	Vocabulary() { }

	~Vocabulary() { }

	void SetWordName(std::string name)
	{
		m_sWord = name;
	}

	void SetWordExplain(std::string explain)
	{
		m_sExplain = explain;
	}

	const std::string getName() const
	{
		return m_sWord;
	}

	Vocabulary(const Vocabulary &vc) {

	}

	Vocabulary& operator= (const Vocabulary & v)
	{
		m_sWord = v.m_sWord;
		m_sExplain = v.m_sExplain;
		return *this;
	}




private:
	std::string m_sWord;
	std::string m_sExplain;
};

bool operator== (const Vocabulary & word1, const Vocabulary & word2)
{
	if (word1.getName() == word2.getName())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!= (const Vocabulary & word1, const Vocabulary & word2)
{
	return !(word1 == word2);
}

int hash(const Vocabulary & e, const int &tableSize)
{
	return hash(e.getName(), tableSize);
}

int hash(const std::string & key, const int &tableSize)
{
	//采用公式：h = (k1*32 + k2) * 32 + k3，将其扩展到n次多项式
	long long int hashVal = 0;
	int count = 0;
	for (auto it = key.begin(); it != key.end(); ++it)
	{
		if (count++ % 2 == 0)
		{
			hashVal += (hashVal << 5) + *it;
		}

	}
	return hashVal %= tableSize;
}

int hash(const int & key, const int &tableSize)
{
	return key % tableSize;
}