#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(15,7,'*');

    // more actions to be included
}

Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 
    char input = mainGameMechsRef -> getInput(); 

    switch(input)
    {              
        case 'w':  // up
            if(myDir == STOP || myDir == LEFT || myDir == RIGHT)
            {
                myDir = UP;
            }
            break;
        case 'a':  // left
            if(myDir == STOP || myDir == UP || myDir == DOWN)
            {
                myDir = LEFT;
            }
            break;
        case 's':  // down
            if(myDir == STOP || myDir == LEFT || myDir == RIGHT)
            {
                myDir = DOWN;
            }
            break;
        case 'd':  // right
            if(myDir == STOP || myDir == UP || myDir == DOWN)
            {
                myDir = RIGHT;
            }
            break;
        default:
            break;
    }      
}

void Player::movePlayer()
{
    // Update position in current direction
    switch(myDir)
    {
        case UP:
            playerPos.y--;
            break;
        case LEFT:
            playerPos.x--;
            break;
        case DOWN:
            playerPos.y++;
            break;
        case RIGHT:
            playerPos.x++;
            break;
        default:
            break;
    }

    // Switch sides at boarder
    if(playerPos.x < 1)
    {
        playerPos.x = 30-2;
    }
    else if(playerPos.x > 30-2)
    {
        playerPos.x = 1;
    }

    if(playerPos.y < 1)
    {
        playerPos.y = 15-2;
    }
    else if(playerPos.y > 15-2)
    {
        playerPos.y = 1;
    }
}