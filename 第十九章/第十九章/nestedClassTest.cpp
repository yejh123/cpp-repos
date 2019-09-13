#include<iostream>
#include <string>
using namespace std;
template<typename T>  
class List {
	template<typename T>
	class Node;
	Node<T>* head;
	int size;
	List():head()
};

template<typename T>
class List<T>::Node {
	T data;
	Node* next;
	Node() = default;
	Node(T d) :data(d) {}
};

