#include "BinaryHeap.h"
#include <iostream>
BinaryHeap::BinaryHeap()
{
    // TODO: or not
    std::vector<HeapElement> elements;
}

bool BinaryHeap::Add(int uniqueId, double weight)
{
    // TODO:
    for (int i = 0; i < elements.size(); i++)
    {
        if (elements[i].uniqueId == uniqueId)
            return false;
    }
    struct HeapElement newElement;
    newElement.uniqueId = uniqueId;
    newElement.weight = weight;
    int index = 0; 
    if(elements.size() == 0)
    {
        elements.push_back(newElement);
        return true;
    }
    while (1)
    {
        if(index >= elements.size()) // if we are at the end of the vector
        {
            elements.push_back(newElement);
            return true;
        }
        else if (elements[index].weight > weight) // if the weight is less than the current weight
        {
            elements.insert(elements.begin() + index, newElement);
            return true;
        }
        else if (elements[index].weight < weight) // if the weight is greater than the current weight
        {
            if (elements[(2 * index) + 1].weight < weight) // if the left child is less than the weight
            {
                index = (2 * index) + 1;
            } 
            else if (elements[(2 * index) + 2].weight < weight)  // if the right child is less than the weight
            {
                index = (2 * index) + 2;
            }
        }
        else // if the weight is equal to the current weight
        {
            elements.insert(elements.begin() + index + 1, newElement); 
            return true;
        }
    }

    return true;
}

bool BinaryHeap::PopHeap(int &outUniqueId, double &outWeight)
{
    // TODO:
    outUniqueId = elements[0].uniqueId;
    outWeight = elements[0].weight;
    elements.erase(elements.begin());
    return true;
}

bool BinaryHeap::ChangePriority(int uniqueId, double newWeight)
{
    // TODO:
    struct HeapElement newElement;
    newElement.uniqueId = uniqueId;
    newElement.weight = newWeight;
    for (int i = 0; i < elements.size(); i++)
    {
        if (elements[i].uniqueId == uniqueId)
        {
            elements.erase(elements.begin() + i);
            break;
        }
    }
    // make sure it is in the right place
    int index = 0;
    while (1)
    {
        if (elements[index].weight > newWeight)
        {
            elements.insert(elements.begin() + index, newElement);
            break;
        }
        else if (elements[index].weight < newWeight)
        {
            if (elements[(2 * index) + 1].weight < newWeight)
            {
                index = (2 * index) + 1;
            }
            else if (elements[(2 * index) + 2].weight < newWeight)
            {
                index = (2 * index) + 2;
            }
        }
        else
        {
            elements.insert(elements.begin() + index + 1, newElement);
            break;
        }
    }
    return true;
}

int BinaryHeap::HeapSize() const
{
    // TODO:
    return elements.size();
}
void BinaryHeap::PrintHeap(){
    for (int i = 0; i < elements.size(); i++)
    {
        std::cout << elements[i].uniqueId << " " << elements[i].weight << std::endl;
    }
}
