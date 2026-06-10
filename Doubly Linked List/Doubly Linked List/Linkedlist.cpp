#include "Linkedlist.h"
#include <iostream>
using namespace std;



Linkedlist::Node::Node(ElemType n) {
	prev = nullptr;
	next = nullptr;
	data = n;
};
Linkedlist::Linkedlist() {
	head = new Node();
	tail = head;
}
Linkedlist::~Linkedlist() {
	Node* p = head;
	while (p != nullptr) {
		Node* q = p->next;
		delete p;
		p = q;
	}
}
void Linkedlist::insertHead(ElemType n) {
	Node* p = new Node;
	p->data = n;
	p->prev = head;
	p->next = head->next;
	if (head->next != nullptr) head->next->prev = p;
	else tail = p;
	head->next = p;
}
void Linkedlist::insertTail(ElemType n) {
	Node* p = new Node;
	p->data = n;
	p->prev = tail;
	tail->next = p;
	p->next = nullptr;
	tail = p;
}
void Linkedlist::insertNode(ElemType n, int pos) {
	Node* p = head;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		if (p == nullptr) return;
		i++;
	}
	Node* q = new Node;
	q->data = n;
	q->next = p->next;
	q->prev = p;
	if (p->next != nullptr) p->next->prev = q;
	else tail = q;
	p->next = q;
}
void Linkedlist::deleteNode(int pos) {
	Node* p = head;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == nullptr) return;
	}
	if (p->next == nullptr) return;
	Node* q = p->next;
	if (q->next != nullptr) q->next->prev = p;
	else tail = p;
	p->next = q->next;
	delete q;
}
void Linkedlist::print() {
	Node* p = head->next;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void Linkedlist::reverseList() {
	Node* first = nullptr;
	Node* second = head->next;
	tail = head->next;
	while (second != nullptr) {
		Node* third = second->next;
		second->prev = third;
		second->next = first;
		first = second;
		second = third;
	}
	head->next = first;
	if (first != nullptr) first->prev = head;
}
