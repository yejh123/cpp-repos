
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
const int BMAX = 50;   //��������


class book
{
public:
	int no;
	char name[20];
	char author[10];
	char date[10];
	int quan;
	int price;
	int b_flag;                                  //1Ϊ�ڼܣ�2Ϊ���
	int b_del;                                   //1Ϊ����, 2Ϊɾ��
	book() {}                               //���캯��
	void setno(int n)
	{
		no = n;                             //ͼ����ȡֵ
	}
	int getno()
	{
		return no;           //����ͼ����ֵ
	}
	void setprice(int p)
	{
		price = p;                             //ͼ��۸�ȡֵ
	}
	int getprice()
	{
		return price;           //����ͼ��۸�ֵ
	}
	void setname(char na[])
	{
		strcpy_s(name, na);
	}
	char* getname()
	{
		return name;  //����ͼ������
	}
	void setauthor(char a[])
	{
		strcpy_s(author, a);
	}
	char* getauthor()
	{
		return author;  //����ͼ������
	}
	void setdate(char d[])
	{
		strcpy_s(date, d);
	}
	char* getdate()
	{
		return date;
	}
	void setquan(int q)
	{
		quan = q;
	}
	int getquan()
	{
		return quan;
	}
	void borbook()
	{
		b_flag = 2;     //����
	}
	void delbook()
	{
		b_del = 2;   //ɾ��
	}
	void addbook(int no, char na[], char author[], int price, char date[], int quan)
	{
		setno(no);
		setname(na);
		setauthor(author);
		setprice(price);
		setdate(date);
		setquan(quan);
		b_flag = 1; //�ڼ�
		b_del = 1;  //����
	}
}
;

class bdatabase
{
public:
	book btarray[BMAX];                                         //ͼ������
	int top;
	bdatabase()
	{

		book b;
		top = -1;
		fstream file("c:\\file\\book.txt", ios::in);
		while (1)
		{
			file.read((char *)&b, sizeof(b));
			if (!file) break;
			top++;
			btarray[top] = b;
		}
		file.close();
	}

	~bdatabase()
	{
		fstream file("c:\\file\\book.txt", ios::out);
		for (int i = 0; i <= top; i++)
		{
			if (btarray[i].b_del == 1)
				file.write((char *)&btarray[i], sizeof(btarray[i]));
		}
		file.close();
	}

	void addbooks()
	{
		book bk;
		int no;
		char bname[20];
		char bau[10];
		char bda[10];
		int qu;
		int pr;

		cout << endl << "���������: ";
		cin >> no;
		cout << endl << "����������: ";
		cin >> bname;
		cout << endl << "����������: ";
		cin >> bau;
		cout << endl << "������۸�: ";
		cin >> pr;
		cout << endl << "�������������";
		cin >> bda;
		cout << endl << "�������������";
		cin >> qu;
		cout << endl;
		bk.b_flag = 1;
		bk.addbook(no, bname, bau, pr, bda, qu);
		top++;
		btarray[top] = bk;
		return;
	}


	int findbooks(int suffix)        //����ͼ�飬����������ڽ����������
	{
		int no;
		cout << "���������: ";
		cin >> no;
		for (int i = 0; i <= top; i++)
		{
			if (btarray[i].no == no && btarray[i].b_del == 1)
			{
				return i;
			}
		}
		return -1;
	}

	int findbooks()                                //����ͼ��
	{
		int no;
		char value[6];
		cout << "���������: ";
		cin >> no;
		for (int i = 0; i <= top; i++)
		{
			if (btarray[i].no == no && btarray[i].b_del == 1)
			{
				if (btarray[i].b_flag == 1) strcpy_s(value, "�ڼ�");
				if (btarray[i].b_flag == 2) strcpy_s(value, "���");
				cout << "���: " << btarray[i].no << " ����: " << btarray[i].name << " ����: " << btarray[i].author << " �۸�: " << btarray[i].price << " ͼ��״̬ :" << value << endl;
				return i;
			}
		}
		return -1;
	}

	void editbooks()
	{
		int cur;
		cur = findbooks();
		if (cur == -1)
		{
			cout << "û���Ȿ��" << endl;
			return;
		}
		cout << "���: " << btarray[cur].no << " ����: " << btarray[cur].name << " ����: " << btarray[cur].author << " �۸�: " << btarray[cur].price << endl;
		cout << "���޸����ݣ�" << endl;
		cout << endl << "�������: ";
		cin >> btarray[cur].name;
		cout << endl << "���ߵ�����:";
		cin >> btarray[cur].author;
		cout << endl << "��ļ۸�";
		cin >> btarray[cur].price;
		return;
	}

	void delbooks()
	{
		int cur;
		cur = findbooks();
		if (cur == -1)
		{
			return;
		}
		if (btarray[cur].b_flag == 2)
		{
			cout << "��ͼ���Ѿ���������ڹ黹����ɾ����" << endl;
			return;
		}
		btarray[cur].b_del = 2;
		return;
	}

	void listbooks()
	{
		char value[6];
		for (int i = 0; i <= top; i++)
		{

			if (btarray[i].b_del == 1)
			{
				if (btarray[i].b_flag == 1) strcpy_s(value, "�ڼ�");
				if (btarray[i].b_flag == 2) strcpy_s(value, "���");
				cout << "���: " << btarray[i].no << " �������: " << btarray[i].name << " ͼ��״̬ :" << value << endl;
			}
		}
		return;
	}
}
;

class reader
{
public:
	int no;
	int sex;     //�����Ա�1��ʾ�У�0��ʾŮ
	char name[20];
	int r_del;  //1���ڣ�2ɾ��
	int r_bor;  //1����飬2û�н��� 
	book brbook;
public:
	void addreader(int id, char na[], int s)
	{
		no = id;
		sex = s;
		strcpy_s(name, na);
		r_del = 1;
	}
	void setbrbook(book bt)
	{
		brbook = bt;
	}

	book getbrbook()
	{
		return brbook;
	}
};

class rdatabase
{
public:
	reader rdarray[BMAX];
	int top;

public:
	rdatabase()
	{
		reader rd;
		top = -1;
		fstream file("d:\\reader.txt", ios::in);
		while (1)
		{
			file.read((char *)&rd, sizeof(rd));
			if (!file) break;
			top++;
			rdarray[top] = rd;
		}
		file.close();
	}

	~rdatabase()
	{
		fstream file("d:\\reader.txt", ios::out);
		for (int i = 0; i <= top; i++)
		{
			if (rdarray[i].r_del == 1)
				file.write((char *)&rdarray[i], sizeof(rdarray[i]));
		}
		file.close();
	}



	void addreaders()
	{
		reader rd;
		int no;
		int rs;
		char rname[20];
		cout << "������ѧ��: ";
		cin >> no;
		cout << endl << "����������: ";
		cin >> rname;
		cout << endl << "�������Ա�1Ϊ�У�0ΪŮ����";
		cin >> rs;
		cout << endl;
		rd.addreader(no, rname, rs);
		rd.r_bor = 2;
		top++;
		rdarray[top] = rd;
		return;
	}
	int findreaders(int suffix)
	{
		int no;
		cout << "������ѧ��: ";
		cin >> no;
		for (int i = 0; i <= top; i++)
		{
			if (rdarray[i].no == no && rdarray[i].r_del == 1)
			{
				return i;
			}
		}
		return -1;

	}


	int findreaders()
	{
		int no;
		char value[3];
		cout << "������ѧ��: ";
		cin >> no;
		for (int i = 0; i <= top; i++)
		{
			if (rdarray[i].no == no && rdarray[i].r_del == 1)
			{
				if (rdarray[i].r_bor == 1) strcpy_s(value, "��");
				if (rdarray[i].r_bor == 2) strcpy_s(value, "��");
				cout << "ѧ��: " << rdarray[i].no << " ����: " << rdarray[i].name << " �Ƿ����: " << value << endl;
				return i;
			}
		}
		return -1;
	}
	void editreaders()
	{

		int cur;
		cur = findreaders();
		if (cur == -1)
		{
			cout << "û�иö���" << endl;
			return;
		}
		cout << "���޸����ݣ�" << endl;
		cout << endl << " ����: ";
		cin >> rdarray[cur].name;
		return;
	}
	void delreaders()
	{
		int cur;
		cur = findreaders();
		if (cur == -1)
		{
			return;
		}
		if (rdarray[cur].r_bor == 1)
		{
			cout << "���û�����ͼ�飬�뻹�����ɾ��" << endl;
			return;
		}
		rdarray[cur].r_del = 2;
		return;
	}
	void listreaders()
	{
		char value[3];
		for (int i = 0; i <= top; i++)
		{

			if (rdarray[i].r_del == 1)
			{
				if (rdarray[i].r_bor == 1) strcpy_s(value, "��");
				if (rdarray[i].r_bor == 2) strcpy_s(value, "��");
				cout << "ѧ��: " << rdarray[i].no << " ����: " << rdarray[i].name << " �Ƿ����: " << value << endl;
			}
		}
		return;
	}


}
;
void borrowtoreturn(char br)
//���黹�麯��
{
	int rdid = 0;
	int bkid = 0;
	int rsuffix, bsuffix;
	bdatabase t_bd;
	rdatabase t_rd;
	if (br == '1')           //����
	{
		rsuffix = t_rd.findreaders(rdid);
		bsuffix = t_bd.findbooks(bkid);
		if (rsuffix == -1 || bsuffix == -1)
			return;
		if (t_bd.btarray[bsuffix].b_flag == 2)
		{
			cout << "ͼ���Ѿ��������ѡ������ͼ��" << endl;
			return;
		}
		if (t_rd.rdarray[rsuffix].r_bor == 1)
		{
			cout << "���Ѿ����ͼ�飬���ȹ黹�ٽ�����ͼ��" << endl;
			return;
		}
		t_bd.btarray[bsuffix].b_flag = 2;
		t_rd.rdarray[rsuffix].r_bor = 1;
		t_rd.rdarray[rsuffix].brbook = t_bd.btarray[bsuffix];
		return;

	}
	if (br == '2')
	{
		rsuffix = t_rd.findreaders(rdid);
		bsuffix = t_bd.findbooks(bkid);
		if (rsuffix == -1 || bsuffix == -1)
			return;

		if (t_rd.rdarray[rsuffix].brbook.no == t_bd.btarray[bsuffix].no)
		{
			t_bd.btarray[bsuffix].b_flag = 1;
			t_rd.rdarray[rsuffix].r_bor = 2;
			t_rd.rdarray[rsuffix].brbook = t_bd.btarray[bsuffix];
		}
		else
		{
			cout << "���������룬���߽��ͼ��Ų���ȷ" << endl;
			return;
		}
		return;
	}
}


void bookjiemain()
{
	cout << "****************************" << endl;
	cout << "*         ͼ��ά��         *" << endl;
	cout << "*        (1)�� ��          *" << endl;
	cout << "*        (2)�� ��          *" << endl;
	cout << "*        (3)ɾ ��          *" << endl;
	cout << "*        (4)�� ��          *" << endl;
	cout << "*        (5)�� ʾ          *" << endl;
	cout << "*        (6)������һ��     *" << endl;
	cout << "****************************" << endl;
}

void readerjiemian()
{
	cout << "****************************" << endl;
	cout << "*         ����ά��         *" << endl;
	cout << "*        (1)�� ��          *" << endl;
	cout << "*        (2)�� ��          *" << endl;
	cout << "*        (3)ɾ ��          *" << endl;
	cout << "*        (4)�� ��          *" << endl;
	cout << "*        (5)�� ʾ          *" << endl;
	cout << "*        (6)������һ��     *" << endl;
	cout << "****************************" << endl;

}

void mainjiemian()
{
	cout << "***********************************************" << endl;
	cout << "*               ͼ �� �� �� ϵ ͳ             *" << endl;
	cout << "*                                             *" << endl;
	cout << "*               (1) �� ��                     *" << endl;
	cout << "*                                             *" << endl;
	cout << "*               (2) �� ��                     *" << endl;
	cout << "*                                             *" << endl;
	cout << "*               (3) ͼ �� �� ��               *" << endl;
	cout << "*                                             *" << endl;
	cout << "*               (4) �� �� �� ��               *" << endl;
	cout << "*                                             *" << endl;
	cout << "*               (0) �� ��                     *" << endl;
	cout << "***********************************************" << endl;
}
void booksmange()
{
	char in;
	bdatabase  bd;
	do {
		bookjiemain();
		cin >> in;
		switch (in)
		{
		case '1':
			bd.addbooks();
			break;
		case '2':
			bd.editbooks();
			break;
		case '3':
			bd.delbooks();
			break;
		case '4':
			bd.findbooks();
			break;
		case '5':
			bd.listbooks();
			break;
		case '6':
			break;
		default:cout << "���������������롣" << endl;;
		}
	} while (in != '6');
	return;
}

void readersmange()
{
	char in;
	rdatabase  bd;
	do {
		readerjiemian();
		cin >> in;
		switch (in)
		{
		case '1':
			bd.addreaders();
			break;
		case '2':
			bd.editreaders();
			break;
		case '3':
			bd.delreaders();
			break;
		case '4':
			bd.findreaders();
			break;
		case '5':
			bd.listreaders();
			break;
		case '6':
			break;
		default:cout << "���������������롣" << endl;
		}
	} while (in != '6');
	return;

}


int main(int argc, char* argv[])
{
	char in;
	do {
		mainjiemian();
		cin >> in;
		switch (in)
		{
		case '1':
			borrowtoreturn(in);
			break;
		case '2':
			borrowtoreturn(in);
			break;
		case '3':
			booksmange();
			break;
		case '4':
			readersmange();
			break;
		case '0':
			break;
		default:cout << "���������������롣" << endl;
		}
	} while (in != '0');
	return 0;
}
