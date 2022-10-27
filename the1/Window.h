#ifndef WINDOW_H
#define WINDOW_H

#include "LinkedList.h"
#include "Tab.h"

class Window
{
public:
    Window();

    Tab getActiveTab();
    bool isEmpty() const;

    void newTab(const Tab &tab);
    void closeTab();
    void moveActiveTabTo(int index);
    void changeActiveTabTo(int index);

    void closeTab(Node<Tab> &tab);
    void addTab(Node<Tab> &tab);

private:
    LinkedList<Tab> tabs;
    int activeTab;
};



#endif //WINDOW_H
