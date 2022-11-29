#include <iostream>

#include "ScapegoatTree.h"

using namespace std;
int main() {

    ScapegoatTree<int> tree, tree2;

    tree.printPretty();

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);
    tree.insert(18);
    tree.insert(19);
    tree.insert(20);
    tree.insert(21);
    tree.insert(22);

    tree.printPretty();
    // test height
    cout << "height: " << tree.getHeight() << endl;
    // test size
    cout << "size: " << tree.getSize() << endl;
    // test remove
    tree.remove(10);

    tree.printPretty();

    // test get
    cout << "get: " << tree.get(10) << endl;
    // test print
    tree.print(inorder);
    tree.print(preorder);
    tree.print(postorder);

    // test copy constructor
    tree2 = ScapegoatTree<int>(tree);
    cout << "tree2: "<< endl;
    tree2.printPretty();
    cout << "tree: "<< endl;
    tree.printPretty();
    

    return 0;
}
