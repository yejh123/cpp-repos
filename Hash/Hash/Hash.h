/************************************************************************/
/* �ļ�˵����
/* ���÷������ӷ�ʵ�ֹ�ϣ������C++��׼���е�vector��listʵ��
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

		HashTable(int size = 101);     //��ʼ����ϣ��Ĵ�С
		~HashTable() {}
		bool contains(const HashedObj & obj);
		bool insert(const HashedObj & obj);
		bool remove(const HashedObj & obj);
	private:

		std::vector<std::list<HashedObj> > theList;   //��ϣ��
		int myhash(const HashedObj & obj) const;   //��ϣ����
	};


	//��������
	template <typename HashedObj>
	HashTable<HashedObj>::HashTable(int size /*= 101*/)
	{
		/*���ݹ�ϣ��Ĵ�С����vector�Ŀռ�*/
		theList.reserve(size);
		theList.resize(size);
	}

	template <typename HashedObj>
	int HashTable<HashedObj>::myhash(const HashedObj & obj) const
	{
		//����object��ͬ���ò�ͬ�汾��hash���غ���
		return hash(obj, theList.size());
	}

	/************************************************************************/
	/* �������ƣ�contains
	/* �������ܣ�����ָ�������Ƿ��ڹ�ϣ����
	/* ����ֵ�����ڷ���true�������ڷ���false
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
	/* �������ƣ�insert
	/* �������ܣ���hash���в���Ԫ�أ����Ԫ���Ѿ������򷵻�false�������������������ǰ�����
	/* ����ֵ���ɹ�����true��ʧ�ܷ��ط���false
	/************************************************************************/
	template <typename HashedObj>
	bool HashTable<HashedObj>::insert(const HashedObj & obj)
	{
		int iHashValue = myhash(obj);

		std::list<HashedObj> & tempList = theList[iHashValue];
		if (contains(obj))
		{
			return false;   //�Ѿ����ڷ���false
		}

		tempList.push_back(obj);
		return true;
	}

	/************************************************************************/
	/* �������ƣ�remove
	/* �������ܣ��ӹ�ϣ����ɾ��ָ��Ԫ�أ����Ԫ�ز������򷵻�false
	/* ����ֵ���ɹ�����true��ʧ�ܷ��ط���false
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


//hash���д��뵥�ʱ��࣬һ�������ʾ��Ӧһ������
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
	//���ù�ʽ��h = (k1*32 + k2) * 32 + k3��������չ��n�ζ���ʽ
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