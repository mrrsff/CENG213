#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
    // You can test your implementations here
    LinkedList<int> *list = new LinkedList<int>();
    int a;
    list->append(1);
    list->append(1);
    list->append(1);
    list->append(1);
    list->append(1);
    list->append(1);
    list->removeNode(list->getFirstNode());
    list->insertAtIndex(0, 1);
    list->removeAllNodes();
    list->print();
 }
