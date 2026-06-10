#pragma once
typedef int ElemType;

class Stack {
public:
	virtual void push(ElemType e) = 0;
	virtual void pop() = 0;
	virtual bool isempty() = 0;
	virtual ElemType gettop() = 0;
	virtual ~Stack() {}
};
class ArrayStack : public Stack {
private:
	ElemType* data;
	int top;
	int capacity;
	void expand();
public:
	ArrayStack(int initcapacity = 5);
	~ArrayStack();
	bool isempty() override;
	void push(ElemType e) override;
	void pop() override;
	ElemType gettop() override;
};
class LinkedStack : public Stack {
private:
	struct Node
	{
		ElemType data;
		Node* next;
		Node();
	};
	Node* head;
public:
	LinkedStack();
	~LinkedStack();
	void push(ElemType e) override;
	void pop() override;
	bool isempty() override;
	ElemType gettop() override;
};