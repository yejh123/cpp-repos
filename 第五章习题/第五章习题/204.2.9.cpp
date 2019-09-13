#include <iostream>
using namespace std;
struct employee
{
	int num;
	int age;
	char sex;
	employee *next;
};
employee *head, *head1;
//������������
employee *create()
{
	employee *head, *p, *pend = NULL;
	char ch;
	head = NULL;
	cout << "\t��������?(y/n)"; cin >> ch;
	if (ch == 'y')
	{
		p = new employee;
		cout << "\t���:";  cin >> p->num;
		cout << "\t����:";  cin >> p->age;
		cout << "\t�Ա�:";  cin >> p->sex;
	}
	else
		goto L0;
	while (ch == 'y')
	{
		if (head == NULL) 
			head = p;
		else 
			pend->next = p;
		pend = p;
		cout << "\t��������?(y/n)"; cin >> ch;
		if (ch == 'y')
		{
			p = new employee;
			cout << "\t���:"; cin >> p->num;
			cout << "\t����:"; cin >> p->age;
			cout << "\t�Ա�:"; cin >> p->sex;
		}
	}
	pend->next = NULL;
L0: return head;
}
//��ʾ����������ȫ��ְ����Ϣ
void show(employee *head)
{
	employee *p = head;
	if (!head) { cout << "\t������" << endl; goto L1; }
	cout << "\t�����е�������: \n";
	while (p)
	{
		cout << '\t' << p->num << "," << p->age << "," << p->sex << endl;
		p = p->next;
	}
L1: return;
}
//ͳ����Ůְ������
void count(employee *head)
{
	employee *p = head;
	int m, f;
	m = 0; f = 0;
	while (p)
	{
		if (p->sex == 'm')
			m++;
		else
			f++;
		p = p->next;
	}
	cout << "\t��ְ��������" << m << endl;
	cout << "\tŮְ��������" << f << endl;
}
//������β�������½��
employee *insert()
{
	employee *pend = head, *p;
	//�ڿ�����β�������½��
	if (!head)
	{
		p = new employee;
		cout << "\t���:";  cin >> p->num;
		cout << "\t����:";  cin >> p->age;
		cout << "\t�Ա�:";  cin >> p->sex;
		head = p;
		p->next = NULL;
		return head;
	}
	//������β�������½��
	while (pend->next != NULL)
	{
		pend = pend->next;
	}
	p = new employee;
	cout << "\t���:";  cin >> p->num;
	cout << "\t����:";  cin >> p->age;
	cout << "\t�Ա�:";  cin >> p->sex;
	pend->next = p;
	pend = p;
	pend->next = NULL;
	return head;
}
//ɾ��ָ����ŵĽ��
employee *del(int bh)
{
	employee *p, *q;
	if (!head)
	{
		cout << "\t������" << endl;
		goto L2;
	}
	//ɾ�����׽��
	if (head->num == bh)
	{
		p = head;
		head = head->next;
		delete p;
		cout << "\t����ѱ�ɾ����" << endl;
		goto L2;
	}
	//ɾ�������׽��
	q = head;
	while (q->next != NULL)
	{
		if (q->next->num == bh)
		{
			p = q->next;      //��ɾ�����
			q->next = p->next;
			delete p;
			cout << "\t����ѱ�ɾ����" << endl;
			goto L2;
		}
		q = q->next;
	}
	cout << "\t�Ҳ�����ɾ����㣡" << endl;
L2:  return (head);
}
//ɾ��ָ������εĽ�㣬���ѱ�ɾ����㱣������һ������
employee *delcreate()
{
	employee *p, *pd, *p1, *q;
	p1 = NULL;
	int flag;
	//���������� 
	if (head == NULL)
	{
		cout << "\t������" << endl;
		goto L3;
	}
	head1 = NULL;
	pd = new employee;
	p = head;
	flag = 0;
	while (p != NULL)
	{
		if (p->age >= 55 && p->age <= 60)
		{
			pd->num = p->num;
			pd->age = p->age;
			pd->sex = p->sex;
			if (head1 == NULL)
				head1 = pd;
			else
				p1->next = pd;
			p1 = pd;
			pd = new employee;
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		cout << "\tû����ɾ���Ľ�㣡" << endl; goto L3;
	}
	p1->next = NULL;
	//��ʾ������
	cout << "\t�������е�������: \n";
	p = head1;
	while (p)
	{
		cout << '\t' << p->num << "," << p->age << "," << p->sex << endl;
		p = p->next;
	}
	//ɾ��ָ������Ľ��
	p = head;
	q = p;
	while (p != NULL)
	{
		if (p->age >= 55 && p->age <= 60)
			if (head->age == p->age)
			{
				pd = head;               //��ɾ�����
				head = head->next;
				delete pd;
				p = head;
				continue;
			}
			else
				if (p->next == NULL)
				{
					pd = p;	   		      //��ɾ�����	      
					q->next = NULL;
					delete pd;
					goto L3;
				}
				else
				{
					pd = p;	 		      //��ɾ�����
					q->next = p->next;
					delete pd;
					p = q->next;
					continue;
				}
		q = p;
		p = p->next;
	}
L3: return (head);
}

int main()
{
	int choice, bh;
L:
	cout << "\n\t\t��������ѡ��\n" << endl;
	cout << "\t 1 --- ������������" << endl;
	cout << "\t 2 --- ��ʾ����������ȫ��ְ����Ϣ" << endl;
	cout << "\t 3 --- ͳ����Ůְ������" << endl;
	cout << "\t 4 --- ��ְ��β�������½��" << endl;
	cout << "\t 5 --- ɾ��ָ����ŵĽ��" << endl;
	cout << "\t 6 --- ɾ��ָ������Ľ�㣬���ѱ�ɾ����㱣������һ������" << endl;
	cout << "\t 0 --- �˳�" << endl;
	cout << "\t\t";
	cin >> choice;
	switch (choice)
	{
	case 1: head = create(); goto L;
	case 2: show(head);  goto L;
	case 3: count(head); goto L;
	case 4: head = insert(); goto L;
	case 5: cout << "\t������ɾ�������:";
		cin >> bh;
		head = del(bh); goto L;
	case 6: head = delcreate(); goto L;
	case 0: cout << " \t�˳���������У�\n" << endl; break;
	default: cout << "\t����������������룡\n" << endl; goto L;
	}
}