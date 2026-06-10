#pragma once
#include <optional>
typedef int ElemType;

class Queue {
public:
	virtual void enqueue(ElemType e) = 0;
	virtual void dequeue() = 0;
	virtual std::optional<ElemType> getfront() = 0;
	virtual bool isempty() = 0;
	virtual ~Queue() {}
};
class ArrayQueue : public Queue {
private:
	ElemType* data;
	int front;
	int rear;
	int size;
	int capacity;
	void expand();
public:
	ArrayQueue(int initcapacity = 5);
	
	~ArrayQueue();
	bool isempty() override;
	void enqueue(ElemType e) override;
	void dequeue() override;
	std::optional<ElemType> getfront() override;
};
class LinkedQueue : public Queue {
private:
	struct Node {
		ElemType data;
		Node* next;
		Node();
	};
	Node* front;
	Node* rear;
public:
	LinkedQueue();
	~LinkedQueue();
	bool isempty() override;
	void enqueue(ElemType e) override;
	void dequeue() override;
	std::optional<ElemType> getfront() override;
};