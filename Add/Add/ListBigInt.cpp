#include "add.h"
#include <iostream>
#include <stdexcept> 


ListBigInt::Node::Node() : data(0) {
    next = nullptr;
}
void ListBigInt::printRecursive(Node* node) const {
    if (node == nullptr) return;
    printRecursive(node->next);
    std::cout << node->data << "";
}
ListBigInt::ListBigInt(const std::string& s1) {
    head = new Node();
    tail = head;
    int len = s1.size();
    for (int i = 0;i < len;i++) {
        Node* p = new Node();
        p->data = s1[i] - '0';
        p->next = head->next;
        head->next = p;
        if (i == 0) tail = p;
    }
    length = len;
}
ListBigInt::~ListBigInt() {
    Node* p = head;
    while (p != nullptr) {
        Node* q = p->next;
        delete p;
        p = q;
    }
}
int ListBigInt::getcount() const {
    return length;
}
ElemType ListBigInt::getvalue(int index) const {
    if (index < 0) throw std::out_of_range("BigInt Error: Index cannot be negative!");
    if (index >= length) return 0;
    Node* p = head->next;
    int i = 0;
    while (p != nullptr && i <= index) {
        if (i == index) return p->data;
        i++;
        p = p->next;
    }
    return 0;
}
void ListBigInt::print() const {
    printRecursive(head->next);
    std::cout << std::endl;
}
void ListBigInt::add(const BigIntBase& other) {
    int len = (this->length > other.getcount()) ? this->length : other.getcount();
    int carry = 0;
    Node* p = head->next;
    for (int i = 0; i < len; i++) {
        int val1 = (p != nullptr) ? p->data : 0;
        int val2 = other.getvalue(i);
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        int digit = sum % 10;
        if (p != nullptr) {
            p->data = digit;
            p = p->next;
        }
        else {
            Node* q = new Node();
            tail->next = q;
            q->data = digit;
            tail = q;
        }
    }
    bool sign = false;
    if (carry != 0) {
        Node* end = new Node();
        tail->next = end;
        end->data = carry;
        tail = end;
        sign = true;
    }
    this->length = (sign) ? len + 1 : len;
}