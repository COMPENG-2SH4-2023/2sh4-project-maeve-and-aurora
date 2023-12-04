#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>
#include <stdlib.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "Player.h" 

using namespace std;


class Food
{
    
    private:
        objPosArrayList* foodBucket;

        //GameMechs* mainGameMechsRef;
        //Player* mainPlayerRef;

    public:
        Food(); //GameMechs* thisGMRef, Player* thisPlayerRef
        ~Food(); 

        void getFoodPos(objPosArrayList &returnPos);        
        bool GenerateFood(objPosArrayList &playerPosList); 
};

#endif