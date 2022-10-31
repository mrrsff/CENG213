#include "Browser.h"

Browser::Browser() {
    // TODO
    windows = LinkedList<Window>();
}

void Browser::newWindow() {
    // TODO
    windows.prepend(Window());
}

void Browser::closeWindow() {
    // TODO
    windows.removeNodeAtIndex(0);
}

void Browser::switchToWindow(int index) {
    // TODO
    windows.moveToIndex(0, index);
}

void Browser::moveTab(Window &window1, Window &window2) {
    // TODO
    
}

void Browser::mergeWindows(Window &source, Window &destination) {
    // TODO
}

void Browser::mergeAllWindows() {
    // TODO
}

void Browser::closeAllWindows() {
    // TODO
}

void Browser::closeEmptyWindows() {
    // TODO
}
