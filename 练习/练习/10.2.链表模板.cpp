#include <iostream>
using namespace std;
template<typename T>
class Node {
public:
	T data;
	Node* next = nullptr;
	Node(T t) :data(t) {}
	void addNode(Node* newNode) {
		if (this->next == nullptr) {
			this->next = newNode;
		}
		else {
			this->next->addNode(newNode);
		}
	}
};
template<typename T>
class List {
public:
	Node<T> *head = nullptr;
	int size;
	void add(T data) {
		Node<T>* newNode = new Node<T>(data);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			head->addNode(newNode);
		}
	}
};
int main() {
	List<double> list;
	for (int i = 0; i < 6; ++i) {
		double d;
		cin >> d;
		list.add(d);
	}
	Node<double>* h = list.head;
	for (int i = 0; i < 6; ++i) {
		cout << h->data << " ";
		h = h->next;
	}
}