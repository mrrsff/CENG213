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
    else windows.removeNodeAtIndex(0);
}

void Browser::switchToWindow(int index) {
    // TODO
    if(index >= windows.getSize() || index < 0) return;
    windows.moveToIndex(index, 0);
}

Window &Browser::getWindow(int index) {
    return windows.getNodeAtIndex(index) -> data;
}

void Browser::moveTab(Window &from, Window &to) {
    // TODO
    if(from.isEmpty()) return;
    else{
        to.newTab(from.getActiveTab());
        to.moveActiveTabTo(9999);
        from.closeTab();
    }
}

void Browser::mergeWindows(Window &window1, Window &window2) {
    // TODO
    if(window2.isEmpty()) return;
    else{
        while(!window2.isEmpty()){
            window2.changeActiveTabTo(0);
            moveTab(window2, window1);
        }
    }
}

void Browser::mergeAllWindows() {
    // TODO
    if(windows.getSize() == 1) return;
    else{
        Window window1 = Window();
        window1.closeTab();
        for(int i=0;i<windows.getSize();i++){
            Window window2 = getWindow(i);
            mergeWindows(window1, window2);
        }
        int temp = windows.getSize();
        closeAllWindows();
        windows.prepend(window1);
        Window empty = Window();
        empty.closeTab();
        for(int i=0;i<temp-1;i++){
            windows.append(empty);
        }
    }
}

void Browser::closeAllWindows() {
    // TODO
    while(!windows.isEmpty()){
        windows.removeNodeAtIndex(0);
    }
}

void Browser::closeEmptyWindows() {
    // TODO
    for(int i = 0; i < windows.getSize(); i++){
        if(windows.getNodeAtIndex(i)->data.isEmpty()){
            windows.removeNodeAtIndex(i);
            i--;
        }
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
