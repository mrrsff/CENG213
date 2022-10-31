#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {
    // You can test your implementations here
    LinkedList<int> *list = new LinkedList<int>();
    list->append(7);
    list->append(5);
    list->append(2);
    list->append(8);
    list->append(10);
    list->append(12);
    cout << "Natural List is:\n";
    for(int i=0;i < list->getSize();i++) cout << list->getNodeAtIndex(i)->data << " -> ";
    cout << endl;
    cout << "List is:\n";
    list->moveToIndex(1,6);
    for(int i=0;i < list->getSize();i++) cout << list->getNodeAtIndex(i)->data << " -> ";
    cout << endl;
}
