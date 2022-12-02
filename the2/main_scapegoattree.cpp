#include <iostream>

#include "ScapegoatTree.h"

using namespace std;
int main() {

    ScapegoatTree<int> tree, tree2;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.printPretty();
    

    /*tree.printPretty();
    // test height
    cout << "height: " << tree.getHeight() << endl;
    // test size
    cout << "size: " << tree.getSize() << endl;
    // test remove
    tree.remove(10);

    tree.printPretty();

    // test get
    cout << "get: " << tree.get(10) << endl;*/

    return 0;
}
