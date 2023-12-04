#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // Direction state

        Player(GameMechs* thisGMRef); //, Food* foodBinRef
        ~Player();

        void getPlayerPos(objPosArrayList &returnPos);
        void updatePlayerDir();
        void movePlayer();
        bool checkFoodConsumption();
        void checkSelfCollision(int x, int y);


    private:
        objPosArrayList* playerPosList;         
        enum Dir myDir;

        // Reference to the Main Game Mechanisms and Food Items
        GameMechs* mainGameMechsRef;
        //Food* mainFoodBinRef;
};

#endif