#include <iostream>
#include "BinaryHeap.h"
#include "MeshGraph.h"
#include "ObjLoader.h"

int main(int argv, const char* argc[])
{
    // You can use to test your code here.
    BinaryHeap heap;
    int a = 500;
    for(int i=a;i>0;i-=3)
    {
        std::cout << "Adding " << i+1 << std::endl;
        heap.Add(i+1, i+1);
    }
    for(int i=a/5;i>25;i-=2)
    {
        std::cout << "Adding " << i+1 << std::endl;
        heap.Add(i+1, i+1);
    }
    heap.PrintHeap();
    return 0;
}