#pragma once
#include <string>
typedef int ElemType;

class BigIntBase {
public:
    virtual ~BigIntBase() = default;
    virtual void add(const BigIntBase& other) = 0;
    virtual void print() const = 0;
    virtual int getcount() const = 0;
    virtual ElemType getvalue(int index) const = 0;
};
class SeqBigInt : public BigIntBase {
private:
    ElemType* data;
    int length;
    int capacity;
    void expand();
public:
    SeqBigInt(const std::string& s1);
    ~SeqBigInt() override;
    int getcount() const override;
    ElemType getvalue(int index) const override;
    void add(const BigIntBase& other) override;
    void print() const override;
};
class ListBigInt : public BigIntBase {
private:
    struct Node {
        ElemType data;
        Node* next;
        Node();
    };
    Node* head;
    Node* tail;
    int length;
    void printRecursive(Node* node) const;
public:
    ListBigInt(const std::string& s1);
    ~ListBigInt() override;
    int getcount() const override;
    ElemType getvalue(int index) const override;
    void print() const override;
    void add(const BigIntBase& other) override;
};
