#include "Quene.h"


LinkedQueue::Node::Node() : data(0) {
	next = nullptr;
}
LinkedQueue::LinkedQueue() {
	front = new Node();
	rear = front;
}
LinkedQueue::~LinkedQueue() {
	Node* p = front;
	while (p != nullptr) {
		Node* q = p;
		p = p->next;
		delete q;
	}
}
bool LinkedQueue::isempty()  {
	return (front == rear);
}
void LinkedQueue::enqueue(ElemType e)  {
	Node* p = new Node();
	rear->next = p;
	p->data = e;
	rear = p;
}
void LinkedQueue::dequeue() {
	if (isempty()) return;
	Node* p = front->next;
	front->next = front->next->next;
	if (rear == p) rear = front;
	delete p;
}
std::optional<ElemType> LinkedQueue::getfront()  {
	if (isempty()) return std::nullopt;
	return front->next->data;
}
