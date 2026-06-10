#include <iostream>
#include "Linkedlist.h"
using namespace std;

int main() {
	Linkedlist list;
	for (int i = 1;i <= 5;i++) {
		list.insertHead((10 * i));
	}
	list.print();
	for (int i = 1;i <= 7;i += 2) {
		list.insertTail((2 * i));
	}
	list.print();
	list.insertNode(3, 114514);
	list.deleteNode(5);
	list.print();
	list.reverseList();
	list.print();
	return 0;
}