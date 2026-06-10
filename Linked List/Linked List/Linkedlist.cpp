#include "Linkedlist.h"
#include <iostream>
using namespace std;


Linkedlist::Node::Node(ElemType e) {
	data = e;
	next = nullptr;
}

Linkedlist::Linkedlist() {
	head = new Node(0);
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
void Linkedlist::insertHead(ElemType e) {
	Node* p = new Node;
	p->data = e;
	p->next = head->next;
	head->next = p;
	if (head == tail) tail = p;
}
void Linkedlist::insertTail(ElemType e) {
	Node* p = new Node;
	p->data = e;
	p->next = nullptr;
	tail->next = p;
	tail = p;
}
void Linkedlist::reverseList() {
	if (head->next == nullptr || head->next->next == nullptr) return;
	Node* first = nullptr;
	Node* second = head->next;
	Node* third = nullptr;
	tail = head->next;
	while (second != nullptr) {
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}
	head->next = first;
}
void Linkedlist::insertNode(int pos, ElemType e) {
	Node* p = head;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == nullptr) return;
	}
	Node* q = new Node;
	q->next = p->next;
	q->data = e;
	p->next = q;
	if (q->next == nullptr) tail = q;
}
void Linkedlist::deletenode(int pos) {
	Node* p = head;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == nullptr) return;
	}
	if (p->next == nullptr) return;
	Node* q = p->next;
	p->next = q->next;
	if (q == tail) tail = p;
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