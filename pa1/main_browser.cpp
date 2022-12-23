#ifndef BROWSERPROJECT_MAIN_BROWSER_H
#define BROWSERPROJECT_MAIN_BROWSER_H

#include "Tab.h"
#include "Node.h"
#include "LinkedList.h"
#include "Window.h"
#include "Browser.h"

using namespace std;

int main()
{
    // You can test your implementations here
    Browser browser;
    browser.newWindow();
    browser.newWindow();
    browser.newWindow();

    browser.getWindow(0).closeTab();
    browser.getWindow(1).closeTab();
    browser.getWindow(2).closeTab();


    browser.getWindow(0).newTab(Tab("002","001","003"));
    browser.getWindow(0).newTab(Tab("020","010","030"));
    browser.getWindow(0).newTab(Tab("022","011","033"));

    browser.getWindow(1).newTab(Tab("202","101","303"));
    browser.getWindow(1).newTab(Tab("220","110","330"));
    browser.getWindow(1).newTab(Tab("222","111","333"));
    browser.getWindow(1).newTab(Tab("200","100","300"));

    browser.getWindow(2).newTab(Tab("002","001","003"));

    browser.mergeAllWindows();
    browser.print();
}

#endif //BROWSERPROJECT_MAIN_BROWSER_H
