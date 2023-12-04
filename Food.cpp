#include "Food.h"

Food::Food() //GameMechs* thisGMRef, Player* thisPlayerRef
{
    // Reference pointers
    //mainGameMechsRef = thisGMRef;
    //mainPlayerRef = thisPlayerRef;

    // Initialize food list
    foodBucket = new objPosArrayList[5];
}

Food::~Food()
{
    delete[] foodBucket;
}


void Food::getFoodPos(objPosArrayList &returnPos)
{
    returnPos = *foodBucket;
}

bool Food::GenerateFood(objPosArrayList &playerPosList)
{
    // Seed random with current time
    srand(time(NULL));

    // Get coordinates in game board range
    foodX = rand() % 27 + 1; //might have to play with ending nums
    foodY = rand() % 12 + 1;
    
    // Verify that the current position doesn't overlap the player
    int i;
    objPos temp;
    for( i=0; i < playerPosList.getSize(); i++)
    {
        playerPosList.getElement(temp, i);

        if ((foodX == temp.x) && (foodY == temp.y))
        {
            return false; 
        }        
    }

    return true; 
}