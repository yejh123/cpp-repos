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
//建立单向链表
employee *create()
{
	employee *head, *p, *pend = NULL;
	char ch;
	head = NULL;
	cout << "\t输入数据?(y/n)"; cin >> ch;
	if (ch == 'y')
	{
		p = new employee;
		cout << "\t编号:";  cin >> p->num;
		cout << "\t年龄:";  cin >> p->age;
		cout << "\t性别:";  cin >> p->sex;
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
		cout << "\t输入数据?(y/n)"; cin >> ch;
		if (ch == 'y')
		{
			p = new employee;
			cout << "\t编号:"; cin >> p->num;
			cout << "\t年龄:"; cin >> p->age;
			cout << "\t性别:"; cin >> p->sex;
		}
	}
	pend->next = NULL;
L0: return head;
}
//显示单向链表中全部职工信息
void show(employee *head)
{
	employee *p = head;
	if (!head) { cout << "\t空链表！" << endl; goto L1; }
	cout << "\t链表中的数据是: \n";
	while (p)
	{
		cout << '\t' << p->num << "," << p->age << "," << p->sex << endl;
		p = p->next;
	}
L1: return;
}
//统计男女职工人数
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
	cout << "\t男职工人数：" << m << endl;
	cout << "\t女职工人数：" << f << endl;
}
//在链表尾部插入新结点
employee *insert()
{
	employee *pend = head, *p;
	//在空链表尾部插入新结点
	if (!head)
	{
		p = new employee;
		cout << "\t编号:";  cin >> p->num;
		cout << "\t年龄:";  cin >> p->age;
		cout << "\t性别:";  cin >> p->sex;
		head = p;
		p->next = NULL;
		return head;
	}
	//在链表尾部插入新结点
	while (pend->next != NULL)
	{
		pend = pend->next;
	}
	p = new employee;
	cout << "\t编号:";  cin >> p->num;
	cout << "\t年龄:";  cin >> p->age;
	cout << "\t性别:";  cin >> p->sex;
	pend->next = p;
	pend = p;
	pend->next = NULL;
	return head;
}
//删除指定编号的结点
employee *del(int bh)
{
	employee *p, *q;
	if (!head)
	{
		cout << "\t空链表！" << endl;
		goto L2;
	}
	//删除链首结点
	if (head->num == bh)
	{
		p = head;
		head = head->next;
		delete p;
		cout << "\t结点已被删除！" << endl;
		goto L2;
	}
	//删除非链首结点
	q = head;
	while (q->next != NULL)
	{
		if (q->next->num == bh)
		{
			p = q->next;      //待删除结点
			q->next = p->next;
			delete p;
			cout << "\t结点已被删除！" << endl;
			goto L2;
		}
		q = q->next;
	}
	cout << "\t找不到需删除结点！" << endl;
L2:  return (head);
}
//删除指定年龄段的结点，并把被删除结点保存在另一链表中
employee *delcreate()
{
	employee *p, *pd, *p1, *q;
	p1 = NULL;
	int flag;
	//建立新链表 
	if (head == NULL)
	{
		cout << "\t空链表！" << endl;
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
		cout << "\t没有需删除的结点！" << endl; goto L3;
	}
	p1->next = NULL;
	//显示新链表
	cout << "\t新链表中的数据是: \n";
	p = head1;
	while (p)
	{
		cout << '\t' << p->num << "," << p->age << "," << p->sex << endl;
		p = p->next;
	}
	//删除指定年龄的结点
	p = head;
	q = p;
	while (p != NULL)
	{
		if (p->age >= 55 && p->age <= 60)
			if (head->age == p->age)
			{
				pd = head;               //待删除结点
				head = head->next;
				delete pd;
				p = head;
				continue;
			}
			else
				if (p->next == NULL)
				{
					pd = p;	   		      //待删除结点	      
					q->next = NULL;
					delete pd;
					goto L3;
				}
				else
				{
					pd = p;	 		      //待删除结点
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
	cout << "\n\t\t请键入操作选择\n" << endl;
	cout << "\t 1 --- 建立单向链表" << endl;
	cout << "\t 2 --- 显示单向链表中全部职工信息" << endl;
	cout << "\t 3 --- 统计男女职工人数" << endl;
	cout << "\t 4 --- 在职工尾部插入新结点" << endl;
	cout << "\t 5 --- 删除指定编号的结点" << endl;
	cout << "\t 6 --- 删除指定年龄的结点，并把被删除结点保存在另一链表中" << endl;
	cout << "\t 0 --- 退出" << endl;
	cout << "\t\t";
	cin >> choice;
	switch (choice)
	{
	case 1: head = create(); goto L;
	case 2: show(head);  goto L;
	case 3: count(head); goto L;
	case 4: head = insert(); goto L;
	case 5: cout << "\t输入需删除结点编号:";
		cin >> bh;
		head = del(bh); goto L;
	case 6: head = delcreate(); goto L;
	case 0: cout << " \t退出程序的运行！\n" << endl; break;
	default: cout << "\t输入错误，请重新输入！\n" << endl; goto L;
	}
}