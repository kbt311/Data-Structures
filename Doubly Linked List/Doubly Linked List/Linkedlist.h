#pragma once
typedef int ElemType;

class Linkedlist {
private:
	struct Node {
		Node* prev;
		Node* next;
		ElemType data;
		Node(ElemType n = 0);
	};
	Node* head;
	Node* tail;
public:
	Linkedlist();
	~Linkedlist();
	void insertHead(ElemType n);
	void insertTail(ElemType n);
	void insertNode(ElemType n, int pos);
	void deleteNode(int pos);
	void print();
	void reverseList();
};