#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // Direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        void getPlayerPos(objPosArrayList &returnPos);
        void updatePlayerDir();
        void movePlayer();
        bool checkFoodConsumption();
    

    private:
        objPosArrayList* playerPosList;         
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif