#include <iostream>
#include "Stack.h"


void ArrayStack::expand() {
	if (top + 1 < capacity) return;
	int newcapacity = (capacity == 0) ? 1 : capacity * 2;
	ElemType* newdata = new ElemType[newcapacity];
	for (int i = 0;i < top + 1;i++) {
		newdata[i] = data[i];
	}
	delete[] data;
	data = newdata;
	capacity = newcapacity;
}
ArrayStack::ArrayStack(int initcapacity) {
	capacity = initcapacity;
	data = new ElemType[capacity];
	top = -1;
}
ArrayStack::~ArrayStack() {
	delete[] data;
}
bool ArrayStack::isempty() {
	return (top == -1);
}
void ArrayStack::push(ElemType e) {
	expand();
	top++;
	data[top] = e;
}
void ArrayStack::pop() {
	if (isempty()) return;
	top--;
}
ElemType ArrayStack::gettop() {
	if (isempty()) return -1;
	return data[top];
}