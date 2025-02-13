#pragma once
#ifndef DOUBLYLINKEDLIST

#include<iostream>
#include <string>
#include <memory>
using namespace std;
class Node
{
	friend class List;
private:
	int val;
	shared_ptr<Node> prev;
	shared_ptr<Node> next;
public:
	Node() {
		prev = nullptr;
		next = nullptr;
	}
	Node(int i) :val(i) {}
};
class List
{
private:
	shared_ptr<Node> head;
	int length = 0;       //记录整数的长度，不包括符号位
	int dlength = 0;      //记录小数的长度，不包括小数点
public:
	void insert(int i = 0)
	{
		shared_ptr<Node> p = make_shared<Node>();
		p->val = 0;
		p->prev = head;
		p->next = head->next;
		(head->next)->prev = p;
		head->next = p;
		++dlength;
	}
	void initializeList(const string& s)
	{
		shared_ptr<Node> p, q;
		head = make_shared<Node> ();
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
		int i;
		if (s.find('.') >= 0 && s.find('.') < s.size())    //存储的是浮点数
		{
			for (i = len - 1; s[i] != '.'; --i)            //从s的最后一个字符开始遍历小数部分
			{
				q = make_shared<Node>();
				q->val = s[i] - '0';         // 字符串ascii值要减去'0'才是真的int值
				q->prev = p;                 // 逆序存储
				p->next = q;
				p = q;
				++dlength;
			}
			--i;
			for (; i >= end; --i)                //遍历s的整数部分
			{
				if (interval % 4)
				{
					q = make_shared<Node>();
					q->val = s[i] - '0';         // 字符串ascii值要减去'0'才是真的int值
					q->prev = p;                 // 逆序存储
					p->next = q;
					p = q;
					++length;
				}
				++interval;
			}
		}
		else                                     //存储的是整数
		{
			for (int i = len - 1; i >= end; --i)
			{
				if (interval % 4)
				{
					q = new Node;
					q->val = s[i] - '0';         // 字符串ascii值要减去'0'才是真的int值
					q->prev = p;                 // 逆序存储
					p->next = q;
					p = q;
					++length;
				}
				++interval;
			}
		}

		// 循环连接
		p->next = head;
		head->prev = p;

	}
	static List add(List a1, List b1)
	{
		int len1 = a1.length;
		int len2 = b1.length;
		List result;
		Node *a, *b;        // a为较长的整数链表头， b为较短的整数链表头
		int dlen1 = a1.dlength;
		int dlen2 = b1.dlength;
		int diff = dlen1 - dlen2;
		while (diff > 0)
		{
			b1.insert();
			--diff;
		}
		while (diff < 0)
		{
			a1.insert();
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
		{   // 如果最后一位还有进位
			// 则创建一个新的结点放到首部
			// 注意插入的顺序
			Node *p = new Node;
			p->val = carry;

			p->next = a->next;
			a->next->prev = p;
			p->prev = a;
			a->next = p;

			a = p;
			++len1;
		}
		a = a->next;       // 回到符号位
		result.head = a;
		result.length = len1;
		result.dlength = a1.dlength;
		return result;
	}
	void print()
	{
		int len = length;
		int dlen = dlength;
		Node* t = head;
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
			cout << ".";
		while (dlen > 0)
		{
			cout << t->val;
			t = t->prev;
			dlen--;
		}
		cout << endl;
	}
	static List sub(List& a1, List& b1)
	{
		int len1 = a1.length;
		int len2 = b1.length;
		Node *a = nullptr, *b = nullptr;       // a为较长的整数链表头， b为较短的整数链表头
		List result;
		int dlen1 = a1.dlength;
		int dlen2 = b1.dlength;
		int diff = dlen1 > dlen2;
		while (diff > 0)
		{
			b1.insert();
			++b1.dlength;
			--diff;
		}
		while (diff < 0)
		{
			a1.insert();
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
			Node * tmp1 = a1.head;
			Node * tmp2 = b1.head;
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
			Node *n = b2.head;
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
};

#endif // !DOUBLYLINKEDLIST.H
