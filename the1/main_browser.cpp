#ifndef BROWSERPROJECT_MAIN_BROWSER_H
#define BROWSERPROJECT_MAIN_BROWSER_H

#include "Tab.h"
#include "Node.h"
#include "LinkedList.h"
#include "Window.h"
#include "Browser.h"

int main()
{
    // You can test your implementations here
    Browser *browser = new Browser();
    browser->print();
    browser->newWindow();
    browser->newWindow();
    browser->newWindow();

    browser->getWindow(0).newTab(Tab("a1","a2","a3"));
    browser->getWindow(0).newTab(Tab("b1","b2","b3"));
    browser->getWindow(0).newTab(Tab("c1","c2","c3"));

    browser->getWindow(1).newTab(Tab("d1","d2","d3"));
    browser->getWindow(1).newTab(Tab("e1","e2","e3"));
    browser->getWindow(1).newTab(Tab("f1","f2","f3"));

    browser->getWindow(2).newTab(Tab("g1","g2","g3"));
    browser->getWindow(2).newTab(Tab("h1","h2","h3"));
    browser->getWindow(2).newTab(Tab("i1","i2","i3"));

    browser->print();    
}

#endif //BROWSERPROJECT_MAIN_BROWSER_H
