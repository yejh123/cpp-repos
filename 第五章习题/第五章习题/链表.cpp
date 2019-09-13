#include<iostream>
#include<string>
using namespace std;
struct Node
{
	string data;
	Node *next;
};
void CreareList(Node * &head)
{
	Node *s = new Node;
	Node *p = s;
	cin >> s->data;
	while (s->data != "0")
	{
		if (head == NULL)
		{
			head = s;
		}
		else
		{
			p->next = s;
			p = s;
			s = new Node;
			cin >> s->data;
		}

	}
	p->next = NULL;      //���һ������next��ֵΪ0����ֹ���ʲ����ڵĵ�ַ��
	delete s;
}
void ShowList(Node *head)
{
	while (head)
	{
		cout << head->data << '\t';
		head = head->next;
	}
	cout << endl;
}
void PushBack(Node *p)       //��*p֮�����*s
{
	Node *s = new Node;
	cin >> s->data;
	s->next = p->next;
	p->next = s;
}
void PushFront(Node * &head)    //�ڱ�ͷ����*s
{
	Node *s = new Node;
	cin >> s->data;
	s->next = head;
	head = s;
}
void Pushforward(Node *p)       //��*p֮ǰ����*s
{
	Node *s = new Node;
	cin >> s->data;
	s->next = p->next;
	p->next = s;
	swap(s->data, p->data);
}
void insert(Node * &head, string str)    //�����ݲ�����������
{
	Node *s = new Node;
	Node *p;
	s->data = str;
	if (!head)
	{
		head = s;
		return;
	}
	if (str < head->data)
	{
		s->next = head;
		head = s;
		return;
	}
	for (p = head; ; p = p->next)
	{
		if (str < p->data)
		{

			s->next = p->next;
			p->next = s;
			swap(s->data, p->data);
			return;
		}

		if (p->next == NULL)
		{
			s->next = p->next;
			p->next = s;
			break;
		}
	}
}
void sort(Node *&head)
{
	Node *a[100];
	Node *p = head;
	int i;
	for (i = 0; p != NULL; ++i)
	{
		a[i] = p;
		p = p->next;
	}
	for (int t1 = 0; t1 < i - 1; ++t1)
	{
		for (int t2 = 0; t2 < i - t1 - 1; ++t2)
		{
			if (a[t2]->data > a[t2 + 1]->data)
			{
				swap(a[t2]->data, a[t2 + 1]->data);         //fhc bji aboj co noq ioc aboqs hio 0
			}
		}
	}
}
int main()
{
	Node *head = NULL;
	CreareList(head);
	ShowList(head);
	sort(head);
	ShowList(head);
	insert(head, "fcuha");
	ShowList(head);
}