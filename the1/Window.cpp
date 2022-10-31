#include "Window.h"

Window::Window() {
    this->activeTab = 0;
    tabs.append(Tab());
}

Tab Window::getActiveTab() {
    // TODO
    if(tabs.isEmpty()) return tabs.getNodeAtIndex(activeTab)->data;
    else return Tab();
}

bool Window::isEmpty() const {
    // TODO
    return tabs.isEmpty();
}

void Window::newTab(const Tab &tab) {
    // TODO
    tabs.insertAtIndex(tab, activeTab + 1);
    activeTab++;
}

void Window::closeTab() {
    // TODO
    tabs.removeNodeAtIndex(activeTab);
    if(tabs.isEmpty()) activeTab = -1;
    activeTab--;
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
    tabs.insertAtIndex(tab.data, activeTab + 1);
}

void Window::print() {
    if(tabs.isEmpty()) std::cout << "Window is empty" << std::endl;
    else std::cout << "The active tab is tab " << activeTab << std::endl;
    tabs.print();
}
