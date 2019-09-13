#include "Manager.h"

void Manager::add() {
	cout << "您可以一直添加多条学生记录，按0可退出" << endl;

	string num, name;
	while (1) {
		cout << "\n请依次输入学生的学号、姓名(按0可退出):" << endl;
		cout << "Demand>";
		cin >> num;
		if (num == "0") {
			cout << "\n已返回到主菜单，若要将记录保存到文件请按8，若要对记录排序请按7!" << endl;
			break;
		}
		cin >> name;
		if (!cin) {
			cout << "\n名次只能填入数字! \n添加学生记录失败，已返回到主菜单!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}
		Student stud(num, name);
		base_ptr->add(stud);
	}
}

void Manager::read() {
	if (typeid(base_ptr).name() == "class std::shared_ptr<class Base>") {
		cout << "未声明文件名" << endl;
		return;
	}
	base_ptr->read();
	cout << "\n已返回到主菜单" << endl;
}

void Manager::store() {
	if (typeid(base_ptr).name() == "class std::shared_ptr<class Base>") {
		cout << "未声明文件名" << endl;
		return;
	}
	base_ptr->store();
	cout << "\n已返回到主菜单" << endl;
}

void Manager::remove() {
	cout << "\n选择查询你要删除的学生的信息(查询学号请按1，查询姓名请按2，查询名次请按3，按0可退出): " << endl;
	cout << "Demand>";
	int flag;
	cin >> flag;

	if (flag != 0) {
		cout << "\n请输入您要查询的内容:" << endl;
		cout << "Demand>";
		string str;
		cin >> str;
		base_ptr->remove(flag, str);
	}
	cout << "\n已返回到主菜单" << endl;
}

void Manager::rollback() {
	cout << "\n以下为已被删除学生记录:" << endl;
	this->base_ptr->rollback();
	cout << "\n已返回主菜单" << endl;
}

void Manager::query() {
	cout << "\n查询学号请按1，查询姓名请按2，查询名次请按3，按0可退出" << endl;
	cout << "Demand>";
	int flag;
	cin >> flag;
	if (flag != 0) {
		cout << "\n请输入您要查询的内容:" << endl;
		cout << "Demand>";
		string str;
		cin >> str;
		base_ptr->query(flag, str);
	}
	cout << "\n已返回到主菜单" << endl;
}

void Manager::revise() {
	cout << "\n查询将要修改学生的信息(查询学号请按1，查询姓名请按2，查询名次请按3，按0可退出): " << endl;
	cout << "Demand>";
	int flag;
	cin >> flag;
	if (flag != 0) {
		cout << "\n请输入您要查询或修改的内容:" << endl;
		cout << "Demand>";
		string str;
		cin >> str;
		base_ptr->revise(flag, str);
	}
	cout << "\n已返回到主菜单" << endl;
}

void Manager::sort() {
	int flag;
	bool bl;
	cout << "\n选择你要排序的指标(输入1表示按num排序，2表示按姓名排序，3表示按名次排序，按0可退出): " << endl;
	cout << "Demand>";
	cin >> flag;
	if (flag != 0) {
		while (flag < 1 && flag>3) {
			cout << "输入错误，请重新输入!(按0可推出)" << endl;
			if (flag == 0)
				return;
		}
		cout << "\n选择你排序方式(输入1表示表示降序排序，0表示升序排序): " << endl;
		cout << "Demand>";
		cin >> bl;
		base_ptr->sort(flag, bl);
	}
	cout << "\n学生信息记录顺序已调整完毕!" << endl;
	cout << "\n已返回到主菜单" << endl;
}

void Manager::clear() {			//清空内存中的记录
	cout << "\n是否确认要清空学生记录回收站(确定请按1，退出请按0)?" << endl;
	bool bl;
	cout << "Demand>";
	cin >> bl;
	if (bl)
		base_ptr->clear();
	cout << "\n清理成功，已返回到主菜单" << endl;
}

void Manager::addCourse() {
	this->base_ptr->addCourse();
	cout << "\n已返回到主菜单" << endl;
}

void Manager::printCourses() {
	this->base_ptr->printCourses();
	cout << "\n已返回到主菜单" << endl;
}

void Manager::readCourses() {
	this->base_ptr->readCourses();
	cout << "\n已返回到主菜单" << endl;
}

void Manager::storeCourses() {
	this->base_ptr->storeCourses();
	cout << "\n已返回到主菜单" << endl;
}

void Manager::addScores() {
	cout << "\n========为学生添加课程成绩信息========" << endl;
	cout << "具体操作如下：\n1、查询你要添加成绩信息的学生\n2、选择该生参加的课程（如果不存在课程则需要另外添加）\n3、输入课程成绩" << endl;
	cout << "\n查询学号请按1，查询姓名请按2，查询名次请按3，按0可退出" << endl;
	cout << "Demand>";
	int flag;
	cin >> flag;
	vector<Student_ptr> vec;
	if (flag != 0) {
		cout << "\n请输入您要查询的内容:" << endl;
		cout << "Demand>";
		string str;
		cin >> str;
		base_ptr->addScores(base_ptr->query(flag, str));
	}
	cout << "\n已返回到主菜单" << endl;
}

void Manager::filesAppend() {
	cout << "请输入到追加到的文件名（按0可退出）:" << endl;
	cout << "Demand>";
	string str;
	cin >> str;
	if (str == "0") {
		return;
	}
	this->base_ptr->append(str);
	cout << "\n已返回到主菜单" << endl;
}