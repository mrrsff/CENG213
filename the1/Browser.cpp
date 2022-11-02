#include "Browser.h"

Browser::Browser() {
    windows.append(Window());
}

void Browser::newWindow() {
    // TODO
    windows.prepend(Window());
}

void Browser::closeWindow() {
    // TODO
    if(windows.isEmpty()) return;
    windows.removeNode(windows.getFirstNode());
}

void Browser::switchToWindow(int index) {
    // TODO
    if(index > windows.getSize()) return;
    windows.moveToIndex(index, 0);
}

Window &Browser::getWindow(int index) {
    return windows.getNodeAtIndex(index) -> data;
}

void Browser::moveTab(Window &from, Window &to) {
    // TODO
    Tab tab = from.getActiveTab();
    Node<Tab> *node = new Node<Tab>(tab);
    from.closeTab();
    to.addTab(*node);
}

void Browser::mergeWindows(Window &window1, Window &window2) {
    // TODO
    while(!window2.isEmpty()){
        moveTab(window2, window1);
    }
}

void Browser::mergeAllWindows() {
    // TODO
    while(windows.getSize() > 1){
        mergeWindows(windows.getNodeAtIndex(0)->data, windows.getNodeAtIndex(1)->data);
    }
}

void Browser::closeAllWindows() {
    // TODO
    while(!windows.isEmpty()){
        closeWindow();
    }
}

void Browser::closeEmptyWindows() {
    // TODO
    Node<Window> *current = windows.getFirstNode();
    while(current != nullptr){
        if(current->data.isEmpty()){
            windows.removeNode(current);
        }
        current = current->next;
    }
}

void Browser::print() {
    Node<Window> *head = windows.getFirstNode();
    if(head == NULL) {
        std::cout << "The browser is empty" << std::endl;
    } else {
        (head -> data).print();
        head = head -> next;
        while(head != windows.getFirstNode()) {
            (head -> data).print();
            head = head -> next;
        }
    }
}
