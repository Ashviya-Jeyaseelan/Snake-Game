#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; // Provides 200 elements on the heap
    listSize = 0;                      // No valid elements in the list upon startup
    arrayCapacity = ARRAY_MAX_CAP;     // Array capacity should be max
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; 
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize == arrayCapacity)
    {
        return;
    }

    for (int i = listSize; i > 0; i--) // Start at empty space after last element, copy last element to new inset position
    {
        aList[i].setObjPos(aList[i - 1]); // This shuffles all the elements towards the tail (right)
    }
    
    aList[0].setObjPos(thisPos); // Insert the new element at the head (or the first position)
    
    listSize++; 
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arrayCapacity)
    {
        return;
    }
    
    // No need to shuffle elements for tail!
    aList[listSize].setObjPos(thisPos); // Insert the element at the tail (or the last position)

    listSize++; 
}

void objPosArrayList::removeHead()
{
    if (listSize == 0) // Error check: If list is empty, remove nothing.
    {
        return;
    }

    for (int i = 0; i < listSize - 1; i++) 
    {
        aList[i].setObjPos(aList[i + 1]); // This shuffles all the elements to the write, overwriting the head
    }

    listSize--;
}

void objPosArrayList::removeTail()
{
    if (listSize == 0) 
    {
        return;
    }

    // No need to shuffle elements for tail!
    listSize--; 
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]); 
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize - 1]); 
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]); 
}