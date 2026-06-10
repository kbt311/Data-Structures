#include <iostream>
#include "Quene.h"
using namespace std;

int main() {
	Queue* myQueue = nullptr;
	myQueue = new ArrayQueue();
	for (int i = 1;i <= 10;i++) {
		myQueue->enqueue(5 * i);
	}
	myQueue->dequeue();
	myQueue->dequeue();
	myQueue->dequeue();
	auto res = myQueue->getfront();
	if (res.has_value()) {
		cout << res.value() << endl;
	}
	delete myQueue;
	myQueue = new LinkedQueue();
	for (int i = 1;i <= 10;i++) {
		myQueue->enqueue(10 * i);
	}
	for (int i = 1;i <= 15;i++) {
		myQueue->dequeue();
		auto res = myQueue->getfront();
		if (res.has_value()) {
			cout << res.value() << endl;
		}
		else cout << "NUll" << endl;
	}
	delete myQueue;
	return 0;
}