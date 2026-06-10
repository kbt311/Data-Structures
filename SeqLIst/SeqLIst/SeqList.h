#pragma once 

typedef int ElemType;

class SeqList {
private:
    ElemType* data;
    int length;
    int capacity;
    void expand(); 

public:
    SeqList(int initcapacity = 5);
    ~SeqList();

    void append(int n);
    void print();
    void Insert(int index, int num);
    void Delete(int index);
    int find(int num);
};