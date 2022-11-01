#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
    // You can test your implementations here
    LinkedList<int> *list = new LinkedList<int>(), *list2;
    list->append(7);
    list->append(5);
    list->append(2);
    list->append(8);
    list->append(10);
    list->prepend(12);
    list2 = new LinkedList<int>(*list);
    list2->print();
    cout << "here" << endl;
    list2 = list;

    list2->print();
    cout << "Natural List is:" << endl;
    for(int i=0;i < list->getSize();i++) cout << list->getNodeAtIndex(i)->data << endl;
    cout << "List is:" << endl;
    list->moveToIndex(1,6);
    for(int i=0;i < list->getSize();i++) cout << list->getNodeAtIndex(i)->data << endl;
    cout << list->getSize() << endl;
    cout << list->isEmpty() << endl;
    cout << list->containsNode(list->getNodeAtIndex(1)) << endl;
    cout << list->getIndex(list->getNodeAtIndex(1)) << endl;
    cout << list->getFirstNode()->data << endl;
    cout << list->getLastNode()->data << endl;
    cout << list->getNode(5)->data << endl;
    cout << list->getNodeAtIndex(1)->data << endl;
    list->insertAfterNode(3,list->getNodeAtIndex(1));
    list->print();
    list->insertAtIndex(4,1);
    list->print();
    list->removeNode(list->getNodeAtIndex(1));
    list->print();
    list->removeNode(5);
    list->print();
    list->removeNodeAtIndex(1);
    list->print();
    list->removeAllNodes();
    list->print();
    return 0;
 }
