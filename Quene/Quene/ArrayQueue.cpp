#include "Quene.h"

void ArrayQueue::expand() {
	if (size < capacity) return;
	int newcapacity = (capacity == 0) ? 1 : 2 * capacity;
	ElemType* newdata = new ElemType[newcapacity];
	for (int j = 0; j < size;j++) {
		newdata[j] = data[(front + j) % capacity];
	}
	delete[] data;
	front = 0;
	rear = size;
	capacity = newcapacity;
	data = newdata;
}

ArrayQueue::ArrayQueue(int initcapacity) :front(0), rear(0), size(0)
{
	capacity = initcapacity;
	data = new ElemType[capacity];
}
ArrayQueue::~ArrayQueue() {
	delete[] data;
}
bool ArrayQueue::isempty()  {
	return (size == 0);
}
void ArrayQueue::enqueue(ElemType e)  {
	expand();
	data[rear] = e;
	rear = (rear + 1) % capacity;
	size++;
}
void ArrayQueue::dequeue()  {
	if (isempty()) return;
	front = (front + 1) % capacity;
	size--;
}
std::optional<ElemType> ArrayQueue::getfront()  {
	if (size == 0) return std::nullopt;
	return data[front];
}