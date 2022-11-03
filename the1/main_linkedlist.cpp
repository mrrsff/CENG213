#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
    // You can test your implementations here
    LinkedList<int> *list = new LinkedList<int>(), *list2;
    int a,b;
    list->append(7);
    list->append(5);
    list->append(2);
    list->append(8);
    list->append(10);
    list->prepend(12);
    list->prepend(12);
    list->print();
    list2 = list;
    list2->removeNode(12);
    list2->print();
    return 0;
 }
