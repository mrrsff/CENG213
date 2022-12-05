#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ScapegoatTree.h"

using namespace std;
int main() {

    srand(time(NULL));
    ScapegoatTree<int> tree, tree2;
    int a=25;
    for(int i=0; i<a;i++){
        tree.insert(i+1);
        tree.printPretty();
    }
    tree.printPretty();

    tree.balance();

    /*for(int i=0; i<a;i++){
        cout << "removing " << i+1 << endl;
        tree.remove(i+1);
    }*/
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
