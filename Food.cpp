#include "Food.h"

Food::Food()
{
    objPos initial;
    initial.setObjPos(0,0,'O');

    // Initialize empty food list of length 5
    foodBucket = new objPosArrayList(5);
    foodBucket->insertHead(initial);
    foodBucket->insertHead(initial);
    foodBucket->insertHead(initial);
    foodBucket->insertHead(initial);
    foodBucket->insertHead(initial);
}

Food::~Food()
{
    // Delete heap members
    delete foodBucket;
}

void Food::getFoodPos(objPosArrayList &returnPos)
{
    // Return addres of food positions
    returnPos = *foodBucket;
}

void Food::getSymbol(char &returnPos, int index)
{
    // Return character symbol of specific food item
    objPos target;
    foodBucket->getElement(target, index);
    returnPos = target.symbol;
}

void Food::GenerateFood(objPosArrayList &playerPosList, int index)
{
    bool foodGen; 
    int i, symbolVar;
    objPos food;
    objPos temp;

    // Get target food item
    foodBucket->getElement(food, index);

    do
    {
        foodGen = true;

        // Get coordinates in game board range
        food.x = rand() % 27 + 1; 
        food.y = rand() % 12 + 1; 

        // Verify that the current position doesn't overlap the player
        for(i=0; i < playerPosList.getSize(); i++)
        {
            playerPosList.getElement(temp, i);

            if ((food.x == temp.x) && (food.y == temp.y)) { foodGen = false; }
        }

        // Verify current position doesn't overlap other food items
        for(i=0; i < 5; i++)
        {
            foodBucket->getElement(temp, i);

            if ((food.x == temp.x) && (food.y == temp.y)) { foodGen = false; }
        }
    }
    while(foodGen == false); 

    // Generate value from 0-100 for symbol
    symbolVar = rand() % 100;

    if(symbolVar < 80) { food.symbol = 'O'; }   // 0-79 = +1 to score and length
    else if(symbolVar < 90) { food.symbol = 'X'; }  // 80-89 = +10 to score
    else { food.symbol = 'I'; } // 90-100 = -1 to length

    // Replace with new food
    foodBucket->removeElement(index);
    foodBucket->insertHead(food);
}