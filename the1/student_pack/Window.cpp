#include "Window.h"

Window::Window() {
    this->activeTab = 0;
    Tab *newTab = new Tab();
    tabs.append(*newTab);
}

Tab Window::getActiveTab() {
    // TODO
}

bool Window::isEmpty() const {
    // TODO
}

void Window::newTab(const Tab &tab) {
    // TODO
}

void Window::closeTab() {
    if(activeTab != -1) {
        // TODO
    }
}

void Window::moveActiveTabTo(int index) {
    if(activeTab != -1) {
        // TODO
    }
}

void Window::changeActiveTabTo(int index) {
    // TODO
}

void Window::closeTab(Node<Tab> &tab) {
    // TODO
}

void Window::addTab(Node<Tab> &tab) {
    // TODO
}
