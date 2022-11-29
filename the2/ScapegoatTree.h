#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cmath>

#include "Node.h"
#include "NoSuchItemException.h"

enum TraversalMethod {preorder, inorder, postorder};

template<class T>
class ScapegoatTree {
public: // DO NOT CHANGE THIS PART.
    ScapegoatTree();

    ScapegoatTree(const ScapegoatTree<T> &obj);

    ~ScapegoatTree();

    bool isEmpty() const;

    int getHeight() const;

    int getSize() const;

    bool insert(const T &element);

    bool remove(const T &element);

    void removeAllNodes();

    const T &get(const T &element) const;

    void print(TraversalMethod tp=inorder) const;

    void printPretty() const;

    ScapegoatTree<T> &operator=(const ScapegoatTree<T> &rhs);

    void balance();

    const T &getCeiling(const T &element) const;

    const T &getFloor(const T &element) const;

    const T &getMin() const;

    const T &getMax() const;

    const T &getNext(const T &element) const;
    

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    void print(Node<T> *node, TraversalMethod tp) const;
    void printPretty(Node<T> *node, int indentLevel, bool isLeftChild) const;

    int getSizeHelper(Node<T> *node) const {
        if(!node) return 0;
        return 1 + getSizeHelper(node->left) + getSizeHelper(node->right);
    }

    bool exists(const T &element, Node<T> *node) const{
        if(!node) return false;
        if(element == node->element) return true;
        if(element < node->element) return exists(element, node->left);
        return exists(element, node->right);
    }

    int getHeightHelper(Node<T> *node) const {
        /* TODO */
        if(!node) return 0;
        int a = getHeightHelper(node->left);
        int b = getHeightHelper(node->right);
        return 1 + (a > b ? a : b);
    }

    void balanceHelper(Node<T> *node) const{
        Node<T> *scapegoat = findScapegoat(node);
        std::cout << "scapegoat: " << scapegoat->element << std::endl;
    }

    void copyHelper(Node<T> *node){
        if(!node) return;
        this->insert(node->element);
        copyHelper(node->left);
        copyHelper(node->right);
    }
    Node<T>* findScapegoat(Node<T> *node) const {
        if(!node) return NULL;
        if(3 * getSizeHelper(node->left) > 2 * getSizeHelper(node) || 3 * getSizeHelper(node->right) > 2 * getSizeHelper(node)){
            return node;
        }
        Node<T> *left = findScapegoat(node->left);
        Node<T> *right = findScapegoat(node->right);
        if(left) return left;
        if(right) return right;
        return NULL;
    }
    

private: // DO NOT CHANGE THIS PART.
    Node<T> *root;

    int upperBound;
};

#endif //TREE_H

template<class T>
ScapegoatTree<T>::ScapegoatTree() {
    /* TODO */
    root = NULL;
    upperBound = 0;
}

template<class T>
ScapegoatTree<T>::ScapegoatTree(const ScapegoatTree<T> &obj) {
    /* TODO */
    root = NULL;
    upperBound = 0;
    copyHelper(obj.root);
}

template<class T>
ScapegoatTree<T>::~ScapegoatTree() {
    /* TODO */
    removeAllNodes();
}

template<class T>
bool ScapegoatTree<T>::isEmpty() const {
    /* TODO */
    return root == nullptr;
}

template<class T>
int ScapegoatTree<T>::getHeight() const {
    /* TODO */
    return getHeightHelper(root);
}

template<class T>
int ScapegoatTree<T>::getSize() const {
    /* TODO */
    return getSizeHelper(root);
}

template<class T>
bool ScapegoatTree<T>::insert(const T &element) {
    /* TODO */
    Node <T> *node = new Node<T>(element, NULL, NULL);
    if(!root){
        root = node;
        return true;
    }
    Node<T> *temp = root;
    while(true){
        if(element == temp->element) return false;
        if(element < temp->element){
            if(!temp->left){
                temp->left = node;
                break;
            }
            temp = temp->left;
        }
        else{
            if(!temp->right){
                temp->right = node;
                break;
            }
            temp = temp->right;
        }
    }
    if(getSize() > upperBound) balance();
    return true;
}

template<class T>
bool ScapegoatTree<T>::remove(const T &element) {
    /* TODO */
}

template<class T>
void ScapegoatTree<T>::removeAllNodes() {
    /* TODO */
    root = NULL;
    upperBound = 0;    
}

template<class T>
const T &ScapegoatTree<T>::get(const T &element) const {
    /* TODO */
    Node<T> *temp = root;
    while(temp){
        if(element == temp->element) return temp->element;
        if(element < temp->element) temp = temp->left;
        else temp = temp->right;
    }
    throw NoSuchItemException();
}

template<class T>
void ScapegoatTree<T>::print(TraversalMethod tp) const {

    if (tp == preorder) {
        /* TODO */
        /* root, left, right */
        std::cout << "BST_preorder{" << std::endl;
        print(root, tp);
        std::cout << std::endl << "}" << std::endl;
    } else if (tp == inorder) {
        // check if the tree is empty?
        if (isEmpty()) {
            // the tree is empty.
            std::cout << "BST_inorder{}" << std::endl;
            return;
        }

        // the tree is not empty.

        // recursively output the tree.
        std::cout << "BST_inorder{" << std::endl;
        print(root, tp);
        std::cout << std::endl << "}" << std::endl;
    } else if (tp == postorder) {
        /* TODO */
        /* left, right, root */
        std::cout << "BST_postorder{" << std::endl;
        print(root, tp);
        std::cout << std::endl << "}" << std::endl;
    }
}

template<class T>
void ScapegoatTree<T>::print(Node<T> *node, TraversalMethod tp) const {

    if (tp == preorder) {
        /* TODO */
        /* root, left, right */
        if(!node) return;

        // print root
        std::cout << "\t" << node->element;

        // left subtree
        if(node->left) std::cout << "," << std::endl;
        print(node->left, tp);

        // right subtree 
        if(node->right) std::cout << "," << std::endl;
        print(node->right, tp);

    } else if (tp == inorder) {
        // check if the node is NULL?
        if (node == NULL)
            return;

        // first, output left subtree and comma (if needed).
        print(node->left, inorder);
        if (node->left) {
            std::cout << "," << std::endl;
        }

        // then, output the node.
        std::cout << "\t" << node->element;

        // finally, output comma (if needed) and the right subtree.
        if (node->right) {
            std::cout << "," << std::endl;
        }
        print(node->right, inorder);
    } else if (tp == postorder) {
        /* TODO */
        /* left, right, root */
        if(!node) return;

        // left subtree
        print(node->left, tp);
        if(node->left) std::cout << "," << std::endl;

        // right subtree 
        print(node->right, tp);
        if(node->right) std::cout << "," << std::endl;

        // print root
        std::cout << "\t" << node->element;

    }
}

template<class T>
void ScapegoatTree<T>::printPretty() const {

    // check if the tree is empty?
    if (isEmpty()) {
        // the tree is empty.
        std::cout << "BST_pretty{}" << std::endl;
        return;
    }

    // the tree is not empty.

    // recursively output the tree.
    std::cout << "BST_pretty{" << std::endl;
    printPretty(root, 0, false);
    std::cout << "}" << std::endl;

}

template<class T>
void ScapegoatTree<T>::printPretty(Node<T> *node, int indentLevel, bool isLeftChild) const {

    // check if the node is NULL?
    if (node == NULL)
        return;

    // output the indentation and the node.
    std::cout << "\t";
    for (int i = 0; i < indentLevel; ++i) {
        std::cout << "---";
    }
    std::cout << (indentLevel == 0 ? "root:" : (isLeftChild ? "l:" : "r:")) << node->element << std::endl;

    // first, output left subtree with one more indentation level.
    printPretty(node->left, indentLevel + 1, true);

    // then, output right subtree with one more indentation level.
    printPretty(node->right, indentLevel + 1, false);
}

template<class T>
ScapegoatTree<T> &ScapegoatTree<T>::operator=(const ScapegoatTree<T> &rhs) {
    /* TODO */
    if(this != &rhs){
        removeAllNodes();
        copyHelper(rhs.root);
    }
    return *this;
}

template<class T>
void ScapegoatTree<T>::balance() {
    /* TODO */
}

template<class T>
const T &ScapegoatTree<T>::getCeiling(const T &element) const {
    /* TODO */
}

template<class T>
const T &ScapegoatTree<T>::getFloor(const T &element) const {
    /* TODO */
}

template<class T>
const T &ScapegoatTree<T>::getMin() const {
    /* TODO */
}

template<class T>
const T &ScapegoatTree<T>::getMax() const {
    /* TODO */
}

template<class T>
const T &ScapegoatTree<T>::getNext(const T &element) const {
    /* TODO */
}
