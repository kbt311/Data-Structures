#include <iostream>
#include "Stack.h"


LinkedStack::Node::Node() {
	data = 0;
	next = nullptr;
}
LinkedStack::LinkedStack() {
	head = new Node();
}
LinkedStack::~LinkedStack() {
	Node* p = head;
	while (p != nullptr) {
		Node* q = p->next;
		delete p;
		p = q;
	}
}
void LinkedStack::push(ElemType e)  {
	Node* p = new Node;
	p->data = e;
	p->next = head->next;
	head->next = p;
}
void LinkedStack::pop()  {
	Node* p = head->next;
	head->next = head->next->next;
	delete p;
}
bool LinkedStack::isempty()  {
	return (head->next == nullptr);
}
ElemType LinkedStack::gettop()  {
	if (isempty()) return -1;
	return head->next->data;
}