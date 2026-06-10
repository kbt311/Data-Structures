#pragma once
typedef int ElemType;
class Linkedlist {
private:
	struct Node
	{
		ElemType data;
		Node* next;
		Node(ElemType e = 0);
	};
	Node* head;
	Node* tail;
public:
	Linkedlist();
	~Linkedlist();
	void insertHead(ElemType e);
	void insertTail(ElemType e);
	void reverseList();
	void insertNode(int pos, ElemType e);
	void deletenode(int pos);
	void print();
};