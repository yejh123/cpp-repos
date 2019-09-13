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
	int length = 0;       //��¼����ĳ��ȣ�����������λ
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
				q->val = s[i] - '0';         // �ַ���asciiֵҪ��ȥ'0'�������intֵ
				q->prev = p;                 // ����洢
				p->next = q;
				p = q;
				++length;
			}
			++interval;
		}

		// ѭ������
		p->next = head;
		head->prev = p;
		
	}
	static List add(const List& a1, const List& b1)
	{
		int len1 = a1.length;
		int len2 = b1.length;
		List result;
		Node *a, *b;        // aΪ�ϳ�����������ͷ�� bΪ�϶̵���������ͷ
		if (len1 > len2)
		{
			a = a1.head;
			b = b1.head;
			result.head = a;
			len1 = a1.length;          // �ϳ�������
			len2 = b1.length;          // �϶�������
		}
		else
		{
			a = b1.head;
			b = a1.head;
			result.head = b;
			len1 = b1.length;          // �ϳ�������
			len2 = a1.length;          // �϶�������
		}

		int cnt = 0;
		int carry = 0;             // �����λֵ
		while (cnt != len1)
		{
			a = a->next;
			b = b->next;

			if (cnt >= len2)    // �Ѿ������϶������ȣ����Բ���Ҫ��b->data
				a->val = a->val + carry;
			else
				a->val = a->val + b->val + carry;
			carry = 0;
			if (a->val >= 10) a->val -= 10, carry = 1;   // ����10��ʾ�н�λֵ
			++cnt;
		}

		if (carry)
		{   // ������һλ���н�λ
			// �򴴽�һ���µĽ��ŵ��ײ�
			// ע������˳��
			Node *p = new Node;
			p->val = carry;

			p->next = a->next;
			a->next->prev = p;
			p->prev = a;
			a->next = p;

			a = p;
			++len1;
		}
		a = a->next;       // �ص�����λ
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
		{ // �ڶ��������Ǳ���� 0 �Ľ��ȥ��
			t = t->prev; // ȥ��ǰ����
			--len;
		}

		while (len)
		{ // ��ͷ��ʼ�������
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
		Node *a = nullptr, *b = nullptr;       // aΪ�ϳ�����������ͷ�� bΪ�϶̵���������ͷ
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
			// ��������ͬʱ�� �Ծ���ֵ�����Ϊ����a
			Node * tmp1 = a1.head;
			Node * tmp2 = b1.head;
			int cnt = 0;
			tmp1 = tmp1->prev;
			tmp2 = tmp2->prev;
			while (cnt != len1)                   //λ���Ӵ�С�Ƚ�
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
			{ // �����������һ���Ļ��� �͵�ִ��������
				a = a1.head;
				b = b1.head;
			}
		}
		
		len1 = a1.length > b1.length ? a1.length : b1.length;          // �ϳ�������
		len2 = a1.length > b1.length ? b1.length : a1.length;          // �϶�������

		int cnt = 0;
		int ex = 0;             // �����λֵ
		while (cnt != len1)
		{
			a = a->next;
			b = b->next;

			if (cnt >= len2)    // �Ѿ������϶������ȣ����Բ���Ҫ��b->data
				a->val = a->val - ex;
			else
				a->val = a->val - b->val - ex;
			ex = 0;
			if (a->val < 0) 
				a->val += 10, ex = 1;   // С��0��ʾ�н�λ
			++cnt;
		}

		// �����ǽϴ�ľ���ֵ��ȥ��С�ľ���ֵ�� �������ղ��������λ�Ľ�λ
		a = a->next;       // �ص�����λ
		result.head = a;
		result.length = len1;      // ע��ͷ�����ȱ仯
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
		{   // ͬ�����ӷ�
			result = add(a1, b1);
		}
		else
		{   // ���������
			result = sub(a1, b1);
		}
		
		return result;
	}
};

#endif // !DOUBLYLINKEDLIST.H
