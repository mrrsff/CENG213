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

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE
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
        if(!node) return 0;
        int a = getHeightHelper(node->left);
        int b = getHeightHelper(node->right);
        return 1 + (a > b ? a : b);
    }

    void copyHelper(Node<T> *node){
        if(!node) return;
        this->insert(node->element);
        copyHelper(node->left);
        copyHelper(node->right);
    }
    
    Node<T>* findScapegoat(Node<T> *node, bool leftChild) {
        if(!node) return NULL;
        if(leftChild) {
            if(getSizeHelper(node) * 2 < getSizeHelper(node->left) * 3) return node;
            return findScapegoat(getParent(node), getParent(node)->left == node);
        }
        else {
            if(getSizeHelper(node) * 2 < getSizeHelper(node->right) * 3) return node;
            return findScapegoat(getParent(node), getParent(node)->left == node);
        }
        return NULL;
    }

    void rebuildScapegoat(Node<T> *scapegoat){
        T* arr = nodesSorted(scapegoat);
        Node<T> *parent = getParent(scapegoat);
        int scapegoatsize = getSizeHelper(scapegoat);
        removeSubtree(scapegoat);
        Node<T> *subroot = nodeBuilder(arr, 0, scapegoatsize - 1, parent);
        if(subroot->element < parent->element) parent->left = subroot;
        else parent->right = subroot;
    }

    T* nodesSorted(Node<T> *node){
        T* arr = new T[getSizeHelper(node)];
        int i = 0;
        inorderHelper(node, arr, i);
        return arr;    
    }

    Node<T> *nodeBuilder(T* arr, int begin, int end, Node<T> *subroot){
        if(begin > end) return NULL;
        int mid = (begin + end) / 2;
        Node<T> *node = new Node<T>(arr[mid],NULL,NULL);
        node->left = nodeBuilder(arr, begin, mid - 1, node);
        node->right = nodeBuilder(arr, mid + 1, end, node);
        return node;
    }

    T* inorderHelper(Node<T> *node, T* arr, int &i) const{
        if(!node) return arr;
        inorderHelper(node->left, arr, i);
        arr[i++] = node->element;
        inorderHelper(node->right, arr, i);
        return arr;
    }

    Node<T> *getParent(Node<T> *node){
        if(!root || root == node) return NULL;
        Node<T> *parent = root;
        while(parent){
            if(parent->left == node || parent->right == node) return parent;
            if(node->element < parent->element) parent = parent->left;
            else parent = parent->right;
        }
        return NULL;
    }

    void removeSubtree(Node<T> *node){
        if(!node) return;
        Node<T> *parent = getParent(node);
        removeSubtree(node->left);
        removeSubtree(node->right);
        if(parent){
            if(parent->left == node) parent->left = NULL;
            else parent->right = NULL;
        }
        delete node;
    }
    
    void balanceHelper(T* arr, int start, int end){
        if(start > end) return;
        int mid = (start + end) / 2;
        insertHelper(arr[mid]);
        balanceHelper(arr, start, mid - 1);
        balanceHelper(arr, mid + 1, end);
    }

    bool insertHelper(const T &element){
        Node <T> *node = new Node<T>(element, NULL, NULL);
        if(!root){
            root = node;
            upperBound++;
            return true;    
        } 
        Node<T> *temp = root;
        while(true){
            if(element == temp->element){
                delete node; // delete the node if it already exists
                return false;
            }
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
        upperBound++;
        return false;
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
    return root == NULL;
}

template<class T>
int ScapegoatTree<T>::getHeight() const {
    /* TODO */
    return getHeightHelper(root)-1;
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
        upperBound++;
        return true;    
    } 
    Node<T> *temp = root;
    while(true){
        if(element == temp->element){
            delete node; // delete the node if it already exists
            return false;
        }
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
    upperBound++;
    if(getHeight() > (log(upperBound)/(log(3.0)-log(2.0)))){
        Node<T> *scapegoat = findScapegoat(temp, element < temp->element);  
        std::cout << "scapegoat: " << scapegoat->element << std::endl;
        rebuildScapegoat(scapegoat);
    }
    return true;
}

template<class T>
bool ScapegoatTree<T>::remove(const T &element) {
    /* TODO */
    if(!root) return false;
    if(exists(element)){
        removeHelper(root, element);
        return true;
    }
    return false;
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
        if (isEmpty()) {
            // the tree is empty.
            std::cout << "BST_preorder{}" << std::endl;
            return;
        }

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

        if (isEmpty()) {
            // the tree is empty.
            std::cout << "BST_postorder{}" << std::endl;
            return;
        }

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
    T* arr = nodesSorted(root);
    int tempsize = getSize();
    removeAllNodes();
    balanceHelper(arr, 0, tempsize-1);
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
    Node<T> *temp = root;
    while (temp->left)temp = temp->left;
    return temp->element;
}

template<class T>
const T &ScapegoatTree<T>::getMax() const {
    /* TODO */
    Node<T> *temp = root;
    while (temp->right)temp = temp->right;
    return temp->element;
}

template<class T>
const T &ScapegoatTree<T>::getNext(const T &element) const {
    /* TODO */
}

