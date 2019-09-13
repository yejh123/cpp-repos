#pragma once
#ifndef DOUBLYLINKEDLIST

#include<iostream>
#include <string>
#include <memory>
using namespace std;
void TurnInt(string &s1, string &s2)
{
	int after_point1, after_point2;
	int pos1 = s1.find_first_of('.');
	int pos2 = s2.find_first_of('.');
	int L1 = s1.length();
	int L2 = s2.length();
	if (pos1 >= 0 && pos1 < L1 - 1) after_point1 = s1.length() - pos1 - 1;
	else after_point1 = 0;
	if (pos2 >= 0 && pos2 < L2 - 1) after_point2 = s2.length() - pos2 - 1;
	else after_point2 = 0;

	int ab = abs(after_point1 - after_point2);
	if (after_point1 != 0 && after_point1 < after_point2)
	{
		s1.erase(pos1, 1);
		for (int i = 1; i <= ab; i++) s1 = s1 + "0";
		s2.erase(pos2, 1);
	}
	else if (after_point2 != 0 && after_point1 >= after_point2)
	{
		s1.erase(pos1, 1);
		for (int i = 1; i <= ab; i++) s2 = s2 + "0";
		s2.erase(pos2, 1);
	}
	else if (after_point1 == 0)
	{
		s2.erase(pos2, 1);
		for (int i = 1; i <= ab; i++) s1 = s1 + "0";
	}
	else if (after_point2 == 0)
	{
		s1.erase(pos1, 1);
		for (int i = 1; i <= ab; i++) s2 = s2 + "0";
	}

}
class Node
{
	friend class List;
private:
	int val;
	shared_ptr<Node> prev;
	shared_ptr<Node> next;
public:
	Node() { }
	Node(int i) :val(i) {}
};
class List
{
	shared_ptr<Node> head = make_shared<Node>();
	int length = 0;       //记录整数的长度，不包括符号位
	int dlength = 0;      //记录小数的长度，不包括小数点
public:
	shared_ptr<Node> push_back(shared_ptr<Node> p, int i = 0)
	{
		shared_ptr<Node> q = make_shared<Node>();
		q->val = i;
		q->prev = p;
		if (p->next)
		{
			q->next = p->next;
			(p->next)->prev = q;
		}
		p->next = q;
		return q;
	}

	bool isZero()
	{
		shared_ptr<Node> p = head->prev;
		for (; p != head; p = p->prev) {
			if (p->val != 0)
				return 0;
		}
		return 1;
	}
	~List() {}
	bool operator== (const List &list);
	bool operator!=(const List& list);
	bool operator>=(const List& list);
	void initializeList(const string& s, bool comma)
	{
		shared_ptr<Node> p = make_shared<Node>();
		head->val = '+';
		p = head;
		int interval = 1;
		int len = s.size();
		int end = 0;
		if (s[0] == '-')
		{
			head->val = '-';
			end = 1;
		}
		int i = len - 1;
		if (s.find('.') >= 0 && s.find('.') < s.size())    //存储小数部分
		{
			for (i = len - 1; s[i] != '.'; --i)            //从s的最后一个字符开始遍历小数部分
			{
				p = push_back(p, s[i] - '0');
				++dlength;
			}
			--i;
		}
		//存储整数部分
		if (comma)
			for (; i >= end; --i)
			{
				if (interval % 4)
				{
					p = push_back(p, s[i] - '0');
					++length;
				}
				++interval;
			}
		else
			for (; i >= end; --i) {
				p = push_back(p, s[i] - '0');
				++length;
			}

		// 循环连接
		p->next = head;
		head->prev = p;
	}
	void print()
	{
		int len = length;
		int dlen = dlength;
		shared_ptr<Node> t = head;
		if (t->val == '-')
		{
			cout << '-';
		}
		t = t->next;
		while (t->val == 0 && dlen > 0)
		{ // 第二个条件是避免把整数的 0 去掉
			t = t->next; // 去掉后导零
			--dlen;
		}

		t = head;
		t = t->prev;
		while (t->val == 0 && len > 1)
		{ // 第二个条件是避免把 0 的结果去掉
			t = t->prev; // 去掉前导零
			--len;
		}
		while (len)
		{ // 从头开始输出链表
			cout << t->val;
			t = t->prev;
			--len;
			if (!(len % 3) && len)
				cout << ",";
		}
		if (dlen > 0)
		{
			if (length == 0)
				cout << "0";
			cout << ".";
		}
		while (dlen > 0)
		{
			cout << t->val;
			t = t->prev;
			dlen--;
		}
		cout << endl;
	}
	static List add(List a1, List b1)
	{
		int len1 = a1.length;
		int len2 = b1.length;
		List result;
		shared_ptr<Node>a, b;                 // a为较长的整数链表头， b为较短的整数链表头
		int dlen1 = a1.dlength;
		int dlen2 = b1.dlength;
		int diff = dlen1 - dlen2;
		while (diff > 0)
		{
			a1.push_back(a1.head, 0);
			++a1.dlength;
			--diff;
		}
		while (diff < 0)
		{
			b1.push_back(a1.head, 0);
			++b1.dlength;
			++diff;
		}
		if (len1 > len2)
		{
			a = a1.head;
			b = b1.head;
			result.head = a;
			len1 = a1.length;          // 较长链表长度
			len2 = b1.length;          // 较短链表长度
		}
		else
		{
			a = b1.head;
			b = a1.head;
			result.head = b;
			len1 = b1.length;          // 较长链表长度
			len2 = a1.length;          // 较短链表长度
		}

		int cnt = 0;
		int carry = 0;             // 保存进位值
		while (cnt != len1 + a1.dlength)
		{
			a = a->next;
			b = b->next;

			if (cnt >= len2 + a1.dlength)    // 已经超过较短链表长度，所以不需要加b->data
				a->val = a->val + carry;
			else
				a->val = a->val + b->val + carry;
			carry = 0;
			if (a->val >= 10) a->val -= 10, carry = 1;   // 超过10表示有进位值
			++cnt;
		}

		if (carry)
		{   // 如果最后一位还有进位, 则创建一个新的结点放到首部
			a = result.push_back(a, carry);
			++len1;
		}
		a = a->next;       // 回到符号位
		result.head = a;
		result.length = len1;
		result.dlength = a1.dlength;
		return result;
	}
	static List mul(string str1, string str2)
	{
		while (str1.find(',') >= 0 && str1.find(',') < str1.size())
			str1.erase(str1.find(','),1);
		while (str2.find(',') >= 0 && str2.find(',') < str2.size())
			str2.erase(str2.find(','),1);
		List result;
		result.initializeList("0", 0);
		int sign = 1;   //sign 为符号位
		string str;
		if (str1[0] == '-')
		{         //确定结果正负 
			sign *= -1;
			str1 = str1.erase(0, 1);
		}
		if (str2[0] == '-')
		{
			sign *= -1;
			str2 = str2.erase(0, 1);
		}
		int d1, d2;
		d1 = str1.find('.');
		d2 = str2.find('.');

		if (d1 >= 0 && d1 < str1.size())
		{
			str1.erase(d1, 1);
			d1 = str1.size() - d1;
		}
		else d1 = 0;
		if (d2 >= 0 && d2 < str2.size())
		{
			str2.erase(d2, 1);
			d2 = str2.size() - d2;
		}
		else d2 = 0;
		int L1, L2;
		L1 = str1.length();
		L2 = str2.length();
		for (int i = L2 - 1; i >= 0; i--) //模拟手工乘法竖式
		{
			string temps;              //temps存当前str2某一位乘于str1的结果    
			int int_res = 0, carry = 0, int2 = str2[i] - '0';  //carry存进位的数量，int2存str2的某一位 
			if (int2 != 0)
			{
				for (int j = 1; j <= L2 - 1 - i; j++) temps = "0" + temps;   //这里就是上面所说的加上相应位数的 0 的操作 
				for (int j = L1 - 1; j >= 0; j--)
				{
					int_res = (int2 * (int(str1[j]) - '0') + carry) % 10;
					carry = (int2 *(int(str1[j]) - '0') + carry) / 10;
					temps = char(int_res + '0') + temps;
				}
				if (carry != 0) temps = char(carry + '0') + temps;
			}
			List tempList;
			tempList.initializeList(temps, 0);
			result = result.solve(result, tempList, '+');         //这里就是上面所说的乘法是基于加法的 
		}
		if (sign == -1)
			result.head->val = '-';
		result.length -= d1 + d2;
		result.dlength = d1 + d2;
		return result;
	}
	static List sub(List& a1, List& b1)
	{
		int len1 = a1.length;
		int len2 = b1.length;
		shared_ptr<Node> a, b;                // a为较长的整数链表头， b为较短的整数链表头
		List result;
		int dlen1 = a1.dlength;
		int dlen2 = b1.dlength;
		int diff = dlen1 > dlen2;
		while (diff > 0)
		{
			b1.push_back(b1.head);
			++b1.dlength;
			--diff;
		}
		while (diff < 0)
		{
			b1.push_back(b1.head);
			++a1.dlength;
			++diff;
		}
		if (len1 > len2)
		{
			a = a1.head;
			b = b1.head;
		}
		else if (len1 < len2)
		{
			a = b1.head;
			b = a1.head;
		}
		else
		{
			// 链表长度相同时， 以绝对值大的数为链表a
			shared_ptr<Node> tmp1 = a1.head;
			shared_ptr<Node> tmp2 = b1.head;
			int cnt = 0;
			tmp1 = tmp1->prev;
			tmp2 = tmp2->prev;
			while (cnt != len1 + a1.dlength)                   //位数从大到小比较
			{
				if (tmp1->val > tmp2->val)
				{
					a = a1.head;
					b = b1.head;
					break;
				}
				else if (tmp1->val < tmp2->val)
				{
					a = b1.head;
					b = a1.head;
					break;
				}
				tmp1 = tmp1->prev;
				tmp2 = tmp2->prev;
				++cnt;
			}
			if (cnt == len1)
			{ // 如果两个数是一样的话， 就得执行这里了
				a = a1.head;
				b = b1.head;
			}
		}

		len1 = a1.length > b1.length ? a1.length : b1.length;          // 较长链表长度
		len2 = a1.length > b1.length ? b1.length : a1.length;          // 较短链表长度

		int cnt = 0;
		int ex = 0;             // 保存借位值
		while (cnt != len1 + a1.dlength)
		{
			a = a->next;
			b = b->next;

			if (cnt >= len2 + a1.dlength)    // 已经超过较短链表长度，所以不需要减b->data
				a->val = a->val - ex;
			else
				a->val = a->val - b->val - ex;
			ex = 0;
			if (a->val < 0)
				a->val += 10, ex = 1;   // 小于0表示有借位
			++cnt;
		}

		// 由于是较大的绝对值减去较小的绝对值， 所以最终不会有最高位的借位
		a = a->next;       // 回到符号位
		result.head = a;
		result.length = len1;      // 注意头部长度变化
		result.dlength = a1.dlength;
		return result;
	}
	List solve(List& a1, List& b1, char sign)
	{
		List result;
		List b2 = b1;
		if (sign == '-')
		{
			shared_ptr<Node>n = b2.head;
			if (n->val == '+')
				n->val = '-';
			else
				n->val = '+';
		}
		if (!((a1.head)->val ^ (b1.head)->val))
		{   // 同号做加法
			result = add(a1, b1);
		}
		else
		{   // 异号做减法
			result = sub(a1, b1);
		}

		return result;
	}

	static List div(string str1, string str2)
	{
		int sign1 = 1;
		if (str1[0] == '-') {
			str1 = str1.erase(0, 1);
			sign1 *= -1;
		}
		if (str2[0] == '-') {
			str2 = str2.erase(0, 1);
			sign1 *= -1;
		}
		if (str2 == "0") {                             //判断除数是否为0
			throw runtime_error("0不能为除数");
		}
		if (str2[0] == '0' && str2[1] == '.')
		{
			bool bl = 1;
			for (int i = 2; i <= 7; ++i)
			{
				if (str2[i] != '0')
				{
					bl = 0;
					break;
				}
			}
			if (bl)
				throw runtime_error("除数绝对值小于10^-6");
		}
		while (str1.find(',') >= 0 && str1.find(',') < str1.size())
			str1.erase(str1.find(','), 1);
		while (str2.find(',') >= 0 && str2.find(',') < str2.size())
			str2.erase(str2.find(','), 1);
		string quotient;                               //商
		if ((str1.find_first_of('.') >= 0 && str1.find_first_of('.') <= str1.length() - 1) || (str2.find_first_of('.') >= 0 && str2.find_first_of('.') <= str2.length() - 1))
		{
			TurnInt(str1, str2);
		}
		str1.erase(0, str1.find_first_not_of('0'));
		str2.erase(0, str2.find_first_not_of('0'));
		int L1, L2;
		L1 = str1.length();
		L2 = str2.length();
		List tempstr;
		string s(str1, 0, L2 -1);
		tempstr.initializeList(s, 0);
		int i = L2 - 1;                                        //i表示除法运行到被除数的第i位
		int cnt = 0;
		while (!tempstr.isZero() || i <= L1 - 1)          //模拟手工除法竖式
		{
			shared_ptr<Node> p = tempstr.head;
			if (i >= L1 )
			{
				if (cnt == 11)                              //确定保留的最大位数 
				{
					if (quotient.back() > '5')
						++quotient[quotient.size() - 2];
					//quotient.erase(quotient.size() - 1, 1);
					break;
				}
				cnt++;
				tempstr.push_back(p);
				++tempstr.length;
			}
			else {
				tempstr.push_back(p, str1[i] - '0');
				++tempstr.length;
			}
			++i;
			for (char ch = '9'; ch >= '0'; ch--)           //试商
			{
				List tempList;
				string s(1, ch);
				tempList = tempList.mul(str2, s);
				if (ch == '0')
				{
					quotient += ch;
					break;
				}
				if (tempstr >= tempList)
				{
					quotient = quotient + ch;
					tempstr = tempstr.solve(tempstr, tempList, '-');
					break;
				}
			}
		}

		int ql = quotient.length();
		if (cnt > 0) quotient.insert(ql - cnt, ".");
		if (quotient[0] == '.') quotient = "0" + quotient;
		if (quotient[quotient.find_first_not_of('0')] != '.')  quotient.erase(0, quotient.find_first_not_of('0'));  //去除结果中的前导0
		if (quotient.empty()) quotient = "0";
		if ((sign1 == -1) && quotient != "0") quotient = "-" + quotient;
		List result;
		result.initializeList(quotient.substr(0,quotient.size()-1), 0);
		return result;
	}
};
bool List::operator==(const List& list)
{
	shared_ptr<Node> l = this->head;
	shared_ptr<Node> r = list.head;
	while (l->next != head || r->next != list.head)
	{
		l = l->next;
		r = r->next;
		if (l->val != r->val)
			return 0;
	}
	if (l->next == head && r->next == list.head)
		return 1;
	else return 0;
}
bool List::operator>=(const List &list)
{
	if (*this == list)
		return 1;
	shared_ptr<Node> l = this->head;
	shared_ptr<Node> r = list.head;
	int len1=this->length, len2=list.length;
	for (int i = 0; l->prev != this->head; ++i)
	{
		l = l->prev;
		if (l->val != 0) {
			len1 = i;
			break;
		}
	}
	for (int i = 0; r->prev != list.head; ++i)
	{
		r = r->prev;
		if (r->val != 0) {
			len2 = i;
			break;
		}
	}
	len1 = this->length - len1;
	len2 = list.length - len2;
	if (len1 > len2)
		return 1;
	else if (len1 < len2)
		return 0;
	while (l!= head || r!= list.head)
	{
		if (l->val > r->val)
			return 1;
		else if (l->val < r->val)
			return 0;
		l = l->prev;
		r = r->prev;
	}
	return 1;
}
bool List::operator!=(const List &list)
{
	return !(*this == list);
}
#endif // !DOUBLYLINKEDLIST.H
