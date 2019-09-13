#include "Manager.h"

void Manager::add() {
	cout << "������һֱ��Ӷ���ѧ����¼����0���˳�" << endl;

	string num, name;
	while (1) {
		cout << "\n����������ѧ����ѧ�š�����(��0���˳�):" << endl;
		cout << "Demand>";
		cin >> num;
		if (num == "0") {
			cout << "\n�ѷ��ص����˵�����Ҫ����¼���浽�ļ��밴8����Ҫ�Լ�¼�����밴7!" << endl;
			break;
		}
		cin >> name;
		if (!cin) {
			cout << "\n����ֻ����������! \n���ѧ����¼ʧ�ܣ��ѷ��ص����˵�!" << endl;
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
		cout << "δ�����ļ���" << endl;
		return;
	}
	base_ptr->read();
	cout << "\n�ѷ��ص����˵�" << endl;
}

void Manager::store() {
	if (typeid(base_ptr).name() == "class std::shared_ptr<class Base>") {
		cout << "δ�����ļ���" << endl;
		return;
	}
	base_ptr->store();
	cout << "\n�ѷ��ص����˵�" << endl;
}

void Manager::remove() {
	cout << "\nѡ���ѯ��Ҫɾ����ѧ������Ϣ(��ѯѧ���밴1����ѯ�����밴2����ѯ�����밴3����0���˳�): " << endl;
	cout << "Demand>";
	int flag;
	cin >> flag;

	if (flag != 0) {
		cout << "\n��������Ҫ��ѯ������:" << endl;
		cout << "Demand>";
		string str;
		cin >> str;
		base_ptr->remove(flag, str);
	}
	cout << "\n�ѷ��ص����˵�" << endl;
}

void Manager::rollback() {
	cout << "\n����Ϊ�ѱ�ɾ��ѧ����¼:" << endl;
	this->base_ptr->rollback();
	cout << "\n�ѷ������˵�" << endl;
}

void Manager::query() {
	cout << "\n��ѯѧ���밴1����ѯ�����밴2����ѯ�����밴3����0���˳�" << endl;
	cout << "Demand>";
	int flag;
	cin >> flag;
	if (flag != 0) {
		cout << "\n��������Ҫ��ѯ������:" << endl;
		cout << "Demand>";
		string str;
		cin >> str;
		base_ptr->query(flag, str);
	}
	cout << "\n�ѷ��ص����˵�" << endl;
}

void Manager::revise() {
	cout << "\n��ѯ��Ҫ�޸�ѧ������Ϣ(��ѯѧ���밴1����ѯ�����밴2����ѯ�����밴3����0���˳�): " << endl;
	cout << "Demand>";
	int flag;
	cin >> flag;
	if (flag != 0) {
		cout << "\n��������Ҫ��ѯ���޸ĵ�����:" << endl;
		cout << "Demand>";
		string str;
		cin >> str;
		base_ptr->revise(flag, str);
	}
	cout << "\n�ѷ��ص����˵�" << endl;
}

void Manager::sort() {
	int flag;
	bool bl;
	cout << "\nѡ����Ҫ�����ָ��(����1��ʾ��num����2��ʾ����������3��ʾ���������򣬰�0���˳�): " << endl;
	cout << "Demand>";
	cin >> flag;
	if (flag != 0) {
		while (flag < 1 && flag>3) {
			cout << "�����������������!(��0���Ƴ�)" << endl;
			if (flag == 0)
				return;
		}
		cout << "\nѡ��������ʽ(����1��ʾ��ʾ��������0��ʾ��������): " << endl;
		cout << "Demand>";
		cin >> bl;
		base_ptr->sort(flag, bl);
	}
	cout << "\nѧ����Ϣ��¼˳���ѵ������!" << endl;
	cout << "\n�ѷ��ص����˵�" << endl;
}

void Manager::clear() {			//����ڴ��еļ�¼
	cout << "\n�Ƿ�ȷ��Ҫ���ѧ����¼����վ(ȷ���밴1���˳��밴0)?" << endl;
	bool bl;
	cout << "Demand>";
	cin >> bl;
	if (bl)
		base_ptr->clear();
	cout << "\n����ɹ����ѷ��ص����˵�" << endl;
}

void Manager::addCourse() {
	this->base_ptr->addCourse();
	cout << "\n�ѷ��ص����˵�" << endl;
}

void Manager::printCourses() {
	this->base_ptr->printCourses();
	cout << "\n�ѷ��ص����˵�" << endl;
}

void Manager::readCourses() {
	this->base_ptr->readCourses();
	cout << "\n�ѷ��ص����˵�" << endl;
}

void Manager::storeCourses() {
	this->base_ptr->storeCourses();
	cout << "\n�ѷ��ص����˵�" << endl;
}

void Manager::addScores() {
	cout << "\n========Ϊѧ����ӿγ̳ɼ���Ϣ========" << endl;
	cout << "����������£�\n1����ѯ��Ҫ��ӳɼ���Ϣ��ѧ��\n2��ѡ������μӵĿγ̣���������ڿγ�����Ҫ������ӣ�\n3������γ̳ɼ�" << endl;
	cout << "\n��ѯѧ���밴1����ѯ�����밴2����ѯ�����밴3����0���˳�" << endl;
	cout << "Demand>";
	int flag;
	cin >> flag;
	vector<Student_ptr> vec;
	if (flag != 0) {
		cout << "\n��������Ҫ��ѯ������:" << endl;
		cout << "Demand>";
		string str;
		cin >> str;
		base_ptr->addScores(base_ptr->query(flag, str));
	}
	cout << "\n�ѷ��ص����˵�" << endl;
}

void Manager::filesAppend() {
	cout << "�����뵽׷�ӵ����ļ�������0���˳���:" << endl;
	cout << "Demand>";
	string str;
	cin >> str;
	if (str == "0") {
		return;
	}
	this->base_ptr->append(str);
	cout << "\n�ѷ��ص����˵�" << endl;
}