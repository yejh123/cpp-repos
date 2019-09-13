#include<iostream>
using namespace std;
//198 8451 21 984 2 34 6 0
//2 3 3 3 4 5 5 6 6 6 6 7 8 9 9 0
struct List { 
	int data;
	List *next;
};
void Count(List *head);
void CreareList(List* &head);
void ShowList(List *head);
int main()
{
	List *head = NULL;
	CreareList(head);
	ShowList(head);
	Count(head);
}
void CreareList(List* &head)
{
	List *s = new List;
	s->next = NULL;
	List *p = NULL;
	cin >> s->data;
	while (s->data != 0)
	{
		if (head == NULL)
		{
			head = s;
		}
		else
		{
			if (s->data < head->data)     //插在表头
			{
				s->next = head;
				head = s;
			}
			else
			{
				for (p = head; p->next != NULL; p = p->next)       //插在表中
				{
					if (p->next->data > s->data)
					{
						s->next = p->next;
						p->next = s;
						break;
					}
				}
				if (p->next == NULL)        //插在表尾
				{
					p->next = s;
				}
			}

		}
		s = new List;
		s->next = NULL;
		cin >> s->data;
	}
	delete s;
}
void ShowList(List *head)
{
	while (head)
	{
		cout << head->data << '\t';
		head = head->next;
	}
	cout << endl;
}
void Count(List *head)
{
	List *p ;
	int n = 1;
	cout << "data\tnumber" << endl;
	for (; head->next != NULL; head = head->next)
	{
		p = head->next;
		if (head->data == p->data)
		{
			++n;
			if (head->next->next == NULL)
			{
				cout << head->data << '\t' << n << endl;
			}
		}
		else
		{
			if (n > 1)
			{
				cout << head->data << '\t' << n << endl;
			}
			n = 1;
		}

	}
}