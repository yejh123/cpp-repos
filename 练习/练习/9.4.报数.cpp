#include<iostream>
using namespace std;
class Node {
public:
	int number;
	Node* next;
	Node(int n):number(n) {

	}
	void remove(Node *front) {
		front->next = this->next;
		delete this;
	}
};
class Loop {
public:
	int size;
	Node* head;
	Loop(int size) :size(size) {
		head = new Node(0);
		Node *p = head;
		for (int i = 1; i < size; ++i) {
			Node *q = new Node(i);
			p->next = q;
			p = q;
		}
		p->next = head;
	}
};
int main() {
	int m, n;
	cin >> n >> m;
	Loop loop(n);
	Node* p = loop.head;
	Node* q = p->next;
	int flag = 0;
	while (p != q) {
		if (flag == 0) {
			for (int i = 0; i < m -2; ++i) {
				p = q;
				q = q->next;
			}
			flag = 1;
		}
		else {
			for (int i = 0; i < m - 1; ++i) {
				p = q;
				q = q->next;
			}
		}
		q->remove(p);
		q = p->next;
	}
	cout << p->number << endl;
}