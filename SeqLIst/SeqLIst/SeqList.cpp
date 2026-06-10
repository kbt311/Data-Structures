#include "SeqList.h"
#include <iostream>
using namespace std;

// 构造函数
SeqList::SeqList(int initcapacity) {
    capacity = initcapacity;
    data = new ElemType[capacity];
    length = 0;
}

// 析构函数
SeqList::~SeqList() {
    delete[] data;
}

// 私有扩容方法
void SeqList::expand() {
    if (length >= capacity) {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
		if (newCapacity < length) newCapacity = length;
        ElemType* newData = new ElemType[newCapacity];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
}

void SeqList::append(int n) {
    expand();
    data[length] = n;
    length++;
}

void SeqList::print() {
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void SeqList::Insert(int index, int num) {
    if (index < 1 || index > length + 1) return;
    expand();
    for (int i = length - 1; i >= index - 1; i--) {
        data[i + 1] = data[i];
    }
    data[index - 1] = num;
    length++;
}

void SeqList::Delete(int index) {
    if (length == 0) return;
    if (index < 1 || index > length) return;
    for (int i = index - 1; i < length - 1; i++) {
        data[i] = data[i + 1];
    }
    length--;
}

int SeqList::find(int num) {
    for (int i = 0; i < length; i++) {
        if (data[i] == num) return i + 1;
    }
    return -1;
}