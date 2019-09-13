#pragma once
#ifndef DOUBLYLINKEDLIST

#include<iostream>
#include <string>
using namespace std;
class Node
{
	friend class List;
private:
	int val;
	Node * prev;
	Node * next;
public:
	Node() {
		prev = nullptr;
		next = nullptr;
	}
	Node(int i) :val(i) {}
	Node(int i, Node *prev, Node *next) :val(i), prev(prev), next(next) {}
};
class List
{
private:
	Node *head;
	int length = 0;       //记录链表的长度，不包括符号位
public:
	void initializeList(const string& s)
	{
		Node* p = nullptr, *q = nullptr;
		head = new Node;
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

		// 循环连接
		p->next = head;
		head->prev = p;
		
	}
	static List add(const List& a1, const List& b1)
	{
		int len1 = a1.length;
		int len2 = b1.length;
		List result;
		Node *a, *b;        // a为较长的整数链表头， b为较短的整数链表头
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
		while (cnt != len1)
		{
			a = a->next;
			b = b->next;

			if (cnt >= len2)    // 已经超过较短链表长度，所以不需要加b->data
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
		return result;
	}
	void print()
	{
		int len = length;

		Node* t = head;
		if (t->val == '-')
		{
			cout << '-';
		}
		t = t->prev;
		while (t->val == 0 && t->prev != head)
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
		cout << endl;
	}
	List sub(const List& a1, const List& b1)
	{
		int len1 = a1.length;
		int len2 = b1.length;
		Node *a = nullptr, *b = nullptr;       // a为较长的整数链表头， b为较短的整数链表头
		List result;
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
			while (cnt != len1)                   //位数从大到小比较
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
		while (cnt != len1)
		{
			a = a->next;
			b = b->next;

			if (cnt >= len2)    // 已经超过较短链表长度，所以不需要减b->data
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
		return result;
	}
	List solve(const List& a1, const List& b1, char sign)
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
