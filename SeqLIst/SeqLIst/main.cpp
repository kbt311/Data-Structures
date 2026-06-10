#include <iostream>
#include "SeqList.h"
using namespace std;

int main() {
    SeqList list;
    for (int i = 1; i <= 10; i++) {
        list.append(i);
    }
    list.print();
    list.find(7);
    list.Delete(2);
    list.Insert(5, 114514);
    list.print();
    return 0;
}