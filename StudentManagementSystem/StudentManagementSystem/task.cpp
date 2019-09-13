#include "Manager.h"
void menu();
Manager& store(shared_ptr<Base>& base_ptr, Manager& manager);
void task() {
	cout << "\t\t\t\t\t******��ӭʹ��ѧ���ɼ�����ϵͳ******\n";
	menu();
	shared_ptr<Base> base_ptr = shared_ptr<Base>(new Base());
	//shared_ptr<Base> uf_ptr = shared_ptr<Base>(new UnaryFile(*base_ptr, (string)"c:\\file\\test.txt", (string)"c:\\file\\courses.txt"));
	shared_ptr<Base> bf_ptr = shared_ptr<Base>(new BinaryFile((string)"c:\\file\\test.txt", (string)"c:\\file\\courses.txt"));
	Manager manager(bf_ptr);
	int i;
	cout << "\nDemand>";
	while (cin >> i) {
		switch (i)
		{
		case 1:manager.read(); break;
		case 2:manager.print(); break;
		case 3:manager.add(); break;
		case 4:manager.remove(); break;
		case 5:manager.revise(); break;
		case 6:manager.query(); break;
		case 7:manager.sort(); break;
		case 8:store(bf_ptr, manager).store(); break;
		case 9:manager.clear(); break;
		case 10:manager.readCourses(); break;
		case 11:manager.printCourses(); break;
		case 12:manager.addScores(); break;
		case 13:manager.addCourse(); break;
		case 14:manager.storeCourses(); break;
		case 15:manager.filesAppend(); break;
		case 16:manager.rollback(); break;
		case 0:menu(); break;
		default:
			cout << "�����������������!" << endl;
		}
		cout << "\nDemand>";
	}
}
void menu() {                                                           
	cout << "\n * * * * * * * * * * * * * * * * * * * * * * * * * ***���˵�*** * * * * * * * * * * * * * * * * * * * * * * * * * \n" <<
		" 1 ���������ļ�����ѧ���ļ���¼����ǰ��\n" <<
		" 2 ����������ʾѧ����¼��\n" <<
		" 3 �����������ѧ����¼\n" <<
		" 4 ��������ɾ��ѧ����¼\n" <<
		" 5 ���������޸�ѧ����¼\n" <<
		" 6 ����������ѯѧ����¼\n" <<
		" 7 ����������ѧ����¼��������\n" <<
		" 8 �����������浱ǰѧ����¼���ļ���\n" <<
		" 9 �����������ѧ����¼����վ\n" <<
		" 10 ���������ļ�����γ�\n" <<
		" 11 ���������鿴���пγ���Ϣ\n" <<
		" 12 ��������Ϊѧ�����óɼ�\n" <<
		" 13 ����������ӿγ�\n" <<
		" 14 �����������浱ǰ�γ̼�¼���ļ���\n" <<
		" 15 ������������ļ���ѧ����Ϣ��¼׷�ӵ�ͬһ���ļ���\n" <<
		" 16 ���������ָ���ɾ��ѧ����¼\n" <<
		" 0 ���������������˵�" <<
		"\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
}
Manager& store(shared_ptr<Base>& base_ptr, Manager& manager) {
	cout << "\n������洢�ļ���(����Ҫ��׺��,����0��ʾĬ�ϻ���ԭ���ļ��洢):" << endl;
	string str;
	cout << "Demand>";
	cin >> str;
	if (str != "0") {
		base_ptr->setLeftFile("c:\\file\\" + str + ".txt");
	}
	manager.setBase_ptr(base_ptr);
	return manager;
}