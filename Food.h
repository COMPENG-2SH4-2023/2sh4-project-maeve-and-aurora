#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>
#include <stdlib.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class Food
{
    
    private:

        int x = 14; 
        int y =5; 
        int score=0; 

        int foodX;
        int foodY;

        int *FoodD; 

    public:
        Food();
        ~Food(); 

        int getFoodX(); 
        int getFoodY(); 

        
        bool GenerateFood(); 
        
};

#endif