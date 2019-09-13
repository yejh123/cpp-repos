#include "Manager.h"
void menu();
Manager& store(shared_ptr<Base>& base_ptr, Manager& manager);
void task() {
	cout << "\t\t\t\t\t******欢迎使用学生成绩管理系统******\n";
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
			cout << "输入错误，请重新输入!" << endl;
		}
		cout << "\nDemand>";
	}
}
void menu() {                                                           
	cout << "\n * * * * * * * * * * * * * * * * * * * * * * * * * ***主菜单*** * * * * * * * * * * * * * * * * * * * * * * * * * \n" <<
		" 1 ————文件导入学生文件记录到当前表单\n" <<
		" 2 ————显示学生记录表单\n" <<
		" 3 ————添加学生记录\n" <<
		" 4 ————删除学生记录\n" <<
		" 5 ————修改学生记录\n" <<
		" 6 ————查询学生记录\n" <<
		" 7 ————对学生记录进行排序\n" <<
		" 8 ————保存当前学生记录到文件中\n" <<
		" 9 ————清空学生记录回收站\n" <<
		" 10 ————文件导入课程\n" <<
		" 11 ————查看所有课程信息\n" <<
		" 12 ————为学生设置成绩\n" <<
		" 13 ————添加课程\n" <<
		" 14 ————保存当前课程记录到文件中\n" <<
		" 15 ————多个文件的学生信息记录追加到同一个文件中\n" <<
		" 16 ————恢复被删除学生记录\n" <<
		" 0 ————呼出主菜单" <<
		"\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
}
Manager& store(shared_ptr<Base>& base_ptr, Manager& manager) {
	cout << "\n请输入存储文件名(不需要后缀名,输入0表示默认或者原来文件存储):" << endl;
	string str;
	cout << "Demand>";
	cin >> str;
	if (str != "0") {
		base_ptr->setLeftFile("c:\\file\\" + str + ".txt");
	}
	manager.setBase_ptr(base_ptr);
	return manager;
}