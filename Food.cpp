#include "Food.h"

Food::Food()
{

}

Food::~Food()
{
    delete[] FoodD;
}

bool Food::GenerateFood()
{
    srand(time(NULL));

    foodX = rand() % 27 + 1; //might have to play with ending nums
    foodY = rand() % 12 + 1;

    if ((foodX == x) && (foodY == y))
    {
        return(false); 
    }

    else
    {
        return(true); 
    }
}