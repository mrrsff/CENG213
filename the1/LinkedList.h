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
    head = NULL;
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &a)
{
    /* TODO */
    int temp = a.getSize();
    size = 0;
    for(int i=0;i<temp;i++){
        append(a.getNodeAtIndex(i)->data);
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    /* TODO */
    if(this == &rhs) return *this;
    removeAllNodes();
    int temp = rhs.getSize();
    for(int i=0;i<temp;i++){
        append(rhs.getNodeAtIndex(i)->data);
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
    for(int i=0;i<size;i++){
        if(temp == node) return true;
        temp = temp->next;
    }
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
    for(int i=0;i<size-1;i++){
        temp = temp->next;
    }
    return temp;
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const
{
    /* TODO */
    if(isEmpty()) return NULL;
    Node<T> *temp = head;
    for(int i=0;i<size;i++){
        if(temp->data == data) return temp;
        temp = temp->next;
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const
{
    /* TODO */
    if(isEmpty()) return NULL;
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
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node<T> *last = getLastNode();
        last->next = temp;
        temp->prev = last;
        temp->next = head;
        head->prev = temp;
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
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node<T> *last = getLastNode();
        temp->next = head;
        temp->prev = last;
        last->next = temp;
        head->prev = temp;
        head = temp;
    }
    size++;
}

template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node)
{
    /* TODO */
    if(!(this->containsNode(node))) return;
    Node<T> *temp = new Node<T>(data);
    Node<T> *after = node->next;
    temp->prev = node;
    temp->next = after;
    node->next = temp;
    after->prev = temp;
    size++;
}

template<class T>
void LinkedList<T>::insertAtIndex(const T &data, int index)
{
    /* TODO */
    if(index >= size) return;
    Node<T> *temp = new Node<T>(data);
    if (head == NULL)
    {
        head = temp;
        head->next = head;
        head->prev = head;
    }
    else{
        Node<T> *before = getNodeAtIndex(index);
        Node<T> *after = before->next;
        temp->prev = before;
        temp->next = after;
        before->next = temp;
        after->prev = temp;
    }
    size++;
}

template<class T>
int LinkedList<T>::getIndex(Node<T> *node) const
{
    /* TODO */
    Node<T> *temp = head;
    for(int i=0;i<size;i++){
        if(temp == node) return i;
        temp = temp->next;
    }
    return -1;
}

template<class T>
void LinkedList<T>::moveToIndex(int currentIndex, int newIndex)
{
    /* TODO */
    
    if(currentIndex >= size || currentIndex == newIndex) return;
    if(currentIndex == 0){
        if(newIndex == size-1) head = head->next;
        else{
            Node<T> *temp = head;
            Node<T> *before = getNodeAtIndex(newIndex);
            Node<T> *after = before->next;
            Node<T> *last = getLastNode();
            head = head->next;
            last->next = head;
            head->prev = last;
            after->prev = temp;
            temp->next = after;
            temp->prev = before;
            before->next = temp;
        }
    }
    else if(currentIndex == size-1){
        if(newIndex == 0)head = head->prev;
        else{
            Node<T> *temp = getLastNode();
            Node<T> *before = getNodeAtIndex(newIndex-1);
            Node<T> *after = before->next;
            Node<T> *newlast = temp->prev;
            newlast->next = head;
            head->prev = newlast;
            temp->next = after;
            temp->prev = before;
            before->next = temp;
            after->prev = temp;
        }
    }
    else if(newIndex == 0){
        Node<T> *temp = getNodeAtIndex(currentIndex);
        Node<T> *before = head;
        Node<T> *after = head->next;
        Node<T> *tempnext = temp->next;
        Node<T> *tempprev = temp->prev;
        
        tempprev->next = tempnext;
        tempnext->prev = tempprev;

        head->next = temp;
        temp->prev = head;
        temp->next = after;
        after->prev = temp;
    }
    else if(newIndex == size-1){
        Node<T> *temp = getNodeAtIndex(currentIndex);
        Node<T> *before = getLastNode();
        Node<T> *after = before->next;
        Node<T> *tempnext = temp->next;
        Node<T> *tempprev = temp->prev;

        tempprev->next = tempnext;
        tempnext->prev = tempprev;

        before->next = temp;
        temp->prev = before;
        temp->next = after;
        after->prev = temp;
    }
    else if(currentIndex < newIndex){
        Node<T> *temp = getNodeAtIndex(currentIndex);
        Node<T> *before = getNodeAtIndex(newIndex);
        Node<T> *after = before->next;
        Node<T> *tempnext = temp->next;
        Node<T> *tempprev = temp->prev;

        tempprev->next = tempnext;
        tempnext->prev = tempprev;

        temp->next = after;
        after->prev = temp;
        temp->prev = before;
        before->next = temp;
    }
    else if(currentIndex > newIndex){
        Node<T> *temp = getNodeAtIndex(currentIndex);
        Node<T> *before = getNodeAtIndex(newIndex-1);
        Node<T> *after = before->next;
        Node<T> *tempprev = temp->prev;
        Node<T> *tempnext = temp->next;
        tempprev->next = tempnext;
        tempnext->prev = tempprev;

        temp->prev = before;
        temp->next = after;
        after->prev = temp;
        before->next = temp;
    }
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
    if(this->containsNode(node) == 0) return;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if(node == head) head = head->next;
    size--;
    delete node;
}

template<class T>
void LinkedList<T>::removeNode(const T &data)
{
    /* TODO */
    for(int i=0;i<size;i++){
        if(getNodeAtIndex(i)->data == data){
            removeNode(getNodeAtIndex(i));
            removeNode(data);
            return;
        }
    }
}

template<class T>
void LinkedList<T>::removeNodeAtIndex(int index)
{
    /* TODO */
    if(index >= size) return;
    Node<T> *temp = getNodeAtIndex(index);
    Node<T> *before = temp->prev;
    Node<T> *after = temp->next;
    before->next = after;
    after->prev = before;
    size--;
    delete temp;
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    Node<T> *temp = head;
    Node<T> *next = temp->next;
    for(int i=0;i<size;i++){
        delete temp;
        temp = next;
        next = temp->next;
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
        std::cout << *node <<" -> ";
        node = node->next;
    }
    while (node != this->getFirstNode());
}

#endif //LINKEDLIST_H
