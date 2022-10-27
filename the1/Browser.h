#ifndef BROWSER_H
#define BROWSER_H

#include "Tab.h"
#include "LinkedList.h"
#include "Window.h"

class Browser
{
public:
    Browser();

    void newWindow();
    void closeWindow();
    void switchToWindow(int index);
    void moveTab(Window &window1, Window &window2);
    void mergeWindows(Window &source, Window &destination);
    void mergeAllWindows();
    void closeAllWindows();
    void closeEmptyWindows();

private:
    LinkedList<Window> windows;
};



#endif //BROWSER_H
