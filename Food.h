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
        objPosArrayList* foodBucket;

    public:
        Food();
        ~Food(); 

        void getFoodPos(objPosArrayList &returnPos);        
        void getSymbol(char &returnPos, int index);
        void GenerateFood(objPosArrayList &playerPosList, int index); 
};

#endif