#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

template <class T>
class LinkedList
{
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &obj);
    ~LinkedList();

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

    int getSize() const;
    bool isEmpty() const;
    bool containsNode(Node<T> *node) const;
    int getIndex(Node<T> *node) const;

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void append(const T &data);
    void prepend(const T &data);
    void insertAfterNode(const T &data, Node<T> *node);
    void insertAtIndex(const T &data, int index);
    void moveToIndex(int currentIndex, int newIndex);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeNodeAtIndex(int index);
    void removeAllNodes();

    void print() const;

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    int size;
};

template<class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj)
{
    /* TODO */
    head = obj.head;
    size = obj.size;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
    removeAllNodes();
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    /* TODO */
    if (this != &rhs)
    {
        removeAllNodes();
        head = rhs.head;
        size = rhs.size;
    }
    return *this;
}

template<class T>
int LinkedList<T>::getSize() const
{
    /* TODO */
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    /* TODO */
    return size == 0;
}

template<class T>
bool LinkedList<T>::containsNode(Node<T> *node) const
{
    /* TODO */
    Node<T> *temp = head;
    while (temp != NULL)
    {
        if (temp == node)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const
{
    /* TODO */
    return head;
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const
{
    /* TODO */
    Node<T> *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const
{
    /* TODO */
    Node<T> *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const
{
    /* TODO */
    Node<T> *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
}

template<class T>
void LinkedList<T>::append(const T &data)
{
    /* TODO */
    Node<T> *temp = new Node<T>(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node<T> *last = getLastNode();
        last->next = temp;
        temp->prev = last;
    }
    size++;
}

template<class T>
void LinkedList<T>::prepend(const T &data)
{
    /* TODO */
    Node<T> *temp = new Node<T>(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    size++;
}

template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node)
{
    /* TODO */
    Node<T> *temp = new Node<T>(data);
    if(this->containsNode(node))
    {
        if (node->next == NULL)
        {
            node->next = temp;
            temp->prev = node;
        }
        else
        {
            temp->next = node->next;
            node->next->prev = temp;
            node->next = temp;
            temp->prev = node;
        }
        size++;
    }
}

template<class T>
void LinkedList<T>::insertAtIndex(const T &data, int index)
{
    /* TODO */
    Node<T> *temp = new Node<T>(data);
    if(index > size){
        return;
    }
    else if(index == 0){
        prepend(data);
    }
    else if(index == size){
        append(data);
    }
    else{
        Node<T> *temp2 = getNodeAtIndex(index);
        temp->next = temp2;
        temp->prev = temp2->prev;
        temp2->prev->next = temp;
        temp2->prev = temp;
        size++;
    }
}

template<class T>
int LinkedList<T>::getIndex(Node<T> *node) const
{
    /* TODO */
    Node<T> *temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp == node)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

template<class T>
void LinkedList<T>::moveToIndex(int currentIndex, int newIndex)
{
    /* TODO */
    if(currentIndex > size) return;
    if(newIndex > size){
        newIndex = size;
    }
    Node<T> *temp = getNodeAtIndex(currentIndex);
    Node<T> *prev = temp->prev;
    Node<T> *next = temp->next;
    Node<T> *newNode = getNodeAtIndex(newIndex);
    Node<T> *newPrev = newNode->prev;
    Node<T> *newNext = newNode->next;
    prev->next = next;
    next->prev = prev;
    newNode->next = temp;
    temp->prev = newNode;
    temp->next = newNext;
    newNext->prev = temp;
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
    Node<T> *temp = head;
    while(temp->next != node) temp = temp->next;
    temp->next = node->next;
    node->next->prev = temp;
    delete node;
}

template<class T>
void LinkedList<T>::removeNode(const T &data)
{
    /* TODO */
    Node<T> *temp = head;
    while(temp->data != data) temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;    
}

template<class T>
void LinkedList<T>::removeNodeAtIndex(int index)
{
    /* TODO */
    Node<T> *temp = getNodeAtIndex(index);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    Node<T> *temp = head;
    Node<T> *next = NULL;
    while(temp != NULL){
        if(temp->next != NULL){
            next = temp->next;
            delete temp;
            temp = next;
        }
        else{
            delete temp;
            delete next;
        }
    }
    size = 0;
}

template<class T>
void LinkedList<T>::print() const
{
    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getFirstNode();

    do {
        std::cout << *node << std::endl;
        node = node->next;
    }
    while (node != this->getFirstNode());
}

#endif //LINKEDLIST_H
