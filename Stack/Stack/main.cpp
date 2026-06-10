#include <iostream>
#include "Stack.h"
using namespace std;



int main() {
	Stack* myStack = nullptr;
	myStack = new ArrayStack();
	for (int i = 1;i <= 10;i++) {
		myStack->push(5 * i);
	}
	myStack->pop();
	myStack->pop();
	myStack->pop();
	cout << myStack->gettop() << endl;
	delete myStack;
	myStack = new LinkedStack();
	for (int i = 1;i <= 10;i++) {
		myStack->push(10 * i);
	}
	myStack->pop();
	myStack->pop();
	myStack->pop();
	cout << myStack->gettop() << endl;
	delete myStack;
	return 0;
}