/*
100 1
3
2 20
1 30
2 10

*/
#include <iostream>
#include <cmath>
using namespace std;
class GameCharacter {
protected:
	int hp;
	int attack;
public:
	GameCharacter(int a, int b) :hp(a), attack(b) {}
	bool isDeath() {
		return hp <= 0;
	}
	int getHp() const {
		return this->hp;
	}
	int getAttack() const {
		return this->attack;
	}
	void setHp(int h) {
		this->hp = h;
	}
	void setAttack(int a) {
		this->attack = a;
	}
};
class Scuter;
class Monster : public GameCharacter {
public:
	Monster(int a, int b) :GameCharacter(a, b) {}
	Monster() :GameCharacter(0, 0) {}
	bool operator<(const Monster& other)const {

	}
	bool compare(const Monster& other, const Scuter& scuter) const;
};
class Scuter : public GameCharacter {
public:
	Scuter(int a, int b) :GameCharacter(a, b) {}
	int LeastLossOfHp(Monster* monster, int num) {
		//降序排序
		for (int i = 0; i < num - 1; ++i) {
			for (int t = 0; t < num - i - 1; ++t) {
				if (monster[t].compare(monster[t + 1], *this)) {
					swap(monster[t], monster[t + 1]);
				}
			}
		}
		int lossHp = 0;
		for (int i = 0; i < num; ++i) {
			int huihe = ceil(double(monster[i].getHp()) / attack);
			cout << "huihe: " << huihe << " hp:" << monster[i].getHp() << " attack:" << monster[i].getAttack() << endl;
			int attackSum = 0;
			for (int t = i; t < num; ++t) {
				attackSum += monster[t].getAttack();
			}
			this->setHp(this->hp - lossHp);
			lossHp += huihe * attackSum;
			cout << "攻击当前怪兽失去血量: " << huihe * attackSum << endl;
		}
		return lossHp;
	}
};
bool Monster::compare(const Monster& other, const Scuter& scuter) const {
	int huihe1 = ceil(double(this->getHp()) / scuter.getAttack());
	int huihe2 = ceil(double(other.getHp()) / scuter.getAttack());
	int lossHp1 = huihe1 * (this->getAttack() + other.getAttack()) + huihe2 * other.getAttack();        //先杀第一个monster耗费的血量
	int lossHp2 = huihe2 * (this->getAttack() + other.getAttack()) + huihe1 * this->getAttack();		//先杀第二个monster耗费的血量
	return lossHp1 > lossHp2;
}
int main() {
	Monster* monster;
	int attack, hp, num;
	while (cin >> hp >> attack) {
		Scuter scuter(hp, attack);
		cin >> num;
		monster = new Monster[num];
		for (int i = 0; i < num; ++i) {
			cin >> hp >> attack;
			monster[i].setHp(hp);
			monster[i].setAttack(attack);
		}
		cout << scuter.LeastLossOfHp(monster, num) << " ";
		if (scuter.isDeath())
		{
			cout << "Dead" << endl;
		}
		else {
			cout << "Alive" << endl;
		}
		delete[]monster;
		monster = nullptr;
	}
}
