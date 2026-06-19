#include "add.h"
#include <iostream>
#include <stdexcept> 

void SeqBigInt::expand() {
    if (length < capacity) return;
    int newcapacity = (capacity == 0) ? 1 : 2 * capacity;
    ElemType* newdata = new ElemType[newcapacity];
    for (int i = 0;i < length;i++) {
        newdata[i] = data[i];
    }
    delete[] data;
    data = newdata;
    capacity = newcapacity;
}
SeqBigInt::SeqBigInt(const std::string& s1) {
    length = s1.size();
    capacity = s1.size();
    data = new ElemType[capacity];
    for (int i = 0;i < length;i++) {
        data[i] = s1[length - 1 - i] - '0';
    }
}
SeqBigInt::~SeqBigInt() {
    delete[] data;
}
int SeqBigInt::getcount() const {
    return length;
}
ElemType SeqBigInt::getvalue(int index) const {
    if (index < 0) throw std::out_of_range("BigInt Error: Index cannot be negative!");
    if (index >= length) return 0;
    return data[index];
}
void SeqBigInt::add(const BigIntBase& other) {
    int len = (this->length > other.getcount()) ? this->length : other.getcount();
    int carry = 0;
    if (len + 1 > capacity) expand();
    for (int i = 0;i < len;i++) {
        int sum = this->getvalue(i) + other.getvalue(i) + carry;
        carry = sum / 10;
        data[i] = sum % 10;
    }
    bool sign = false;
    if (carry != 0) {
        data[len] = carry;
        sign = true;
    }
    this->length = (sign) ? len + 1 : len;
}
void SeqBigInt::print() const {
    for (int i = length - 1;i >= 0;i--) {
        std::cout << data[i] << "";
    }
    std::cout << std::endl;
}