#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
    // You can test your implementations here
    LinkedList<int> *list = new LinkedList<int>(), *list2;
    list->append(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);
    list->append(6);
    list2 = new LinkedList<int>(*list);
    list2 = list;
    list2->print();
    delete list;
    delete list2;
 }
