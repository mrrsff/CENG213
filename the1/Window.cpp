#include "Window.h"

Window::Window() {
    this->activeTab = 0;
    tabs.append(Tab());
}

Tab Window::getActiveTab() {
    // TODO
    if(tabs.isEmpty()) return Tab();
    else return tabs.getNodeAtIndex(activeTab)->data;
}

bool Window::isEmpty() const {
    // TODO
    return tabs.isEmpty();
}

void Window::newTab(const Tab &tab) {
    // TODO
    tabs.insertAtIndex(tab,++activeTab);
}

void Window::closeTab() {
    // TODO
    tabs.removeNodeAtIndex(activeTab);
    if(tabs.isEmpty()) activeTab = -1;
    else activeTab++;
}

void Window::moveActiveTabTo(int index) {
    // TODO
    if(index > tabs.getSize()) tabs.moveToIndex(activeTab ,tabs.getSize());
    else{
        tabs.moveToIndex(activeTab, index);
    }
    activeTab = index;
}

void Window::changeActiveTabTo(int index) {
    // TODO
    if(index > tabs.getSize()) return;
    activeTab = index;
}

void Window::addTab(Node<Tab> &tab) {
    // TODO
    if(tabs.isEmpty()) activeTab = tabs.getSize();
    tabs.append(tab.data);
}

void Window::print() {
    if(tabs.isEmpty()) std::cout << "Window is empty" << std::endl;
    else std::cout << "The active tab is tab " << activeTab << std::endl;
    tabs.print();
}
