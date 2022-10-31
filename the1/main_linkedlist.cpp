#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
    // You can test your implementations here
    float a = 4;
    LinkedList<int> *list = new LinkedList<int>();
    list->print();
    cout << list->isEmpty() << endl;
    list->prepend(4);
    list->append(5);
    list->append(6);
    list->append(1);
    list->append(10);
    cout << list->getFirstNode()->data << endl;
    cout << list->getLastNode()->data << endl;
    cout << list->getNodeAtIndex(3)->data << endl;
    cout << list->getSize() << endl;
    cout << list->containsNode(list->getFirstNode()) << endl;
    list->removeAllNodes();
}
