#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    sizeList = 0;
    sizeArray = 200;
    aList = new objPos[sizeArray];
}

objPosArrayList::~objPosArrayList()
{
    delete aList;
}

int objPosArrayList::getSize()
{
    return sizeList;   
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList == sizeArray)
    {
        return;
    }

    // Shuffle all elements back by one 
    for(int i = sizeList; i > 0 ; i--)
    {
        aList[i-1].getObjPos(aList[i]);
    }

    // Overwrite first element 
    thisPos.getObjPos(aList[0]);

    sizeList++; // Increase size of the list by one
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList == sizeArray)
    {
        return;
    }
        
    thisPos.getObjPos(aList[sizeList++]);
}

void objPosArrayList::removeHead()
{
    if(sizeList <= 0)
    {
        return;
    }

    // Shuffling Forwards
    for(int i = 0; i < sizeList-1;i++)
    {
        aList[i+1].getObjPos(aList[i]);
    }

    sizeList--;
}

void objPosArrayList::removeTail()
{
    if(sizeList <= 0)
    {
        return;
    }

    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    aList[0].getObjPos(returnPos);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    aList[sizeList-1].getObjPos(returnPos);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    aList[index].getObjPos(returnPos);
}
