#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos startPos; // Temp object for starting position
    startPos.setObjPos(15,7,'*');

    playerPosList = new objPosArrayList[200]; // Initialize player list with starting position
    playerPosList->insertHead(startPos);
}

Player::~Player()
{
    // Delete heap members
    delete playerPosList;
    delete mainGameMechsRef;
}

void Player::getPlayerPos(objPosArrayList &returnPos)
{
    // Return address of player positions
    returnPos = *playerPosList; 
}

void Player::updatePlayerDir()
{
    // Get current input 
    char input = mainGameMechsRef -> getInput(); 

    // Change direction to new input according to direction change logic
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
    objPos currentPos;
    objPos nextPos;
    playerPosList->getHeadElement(currentPos); // Get current first position
    nextPos.setObjPos(currentPos.x, currentPos.y, currentPos.symbol); // Copy to next position

    // Update next position in current direction
    switch(myDir)
    {
        case UP:
            nextPos.y = currentPos.y - 1;
            nextPos.x = currentPos.x;
            break;
        case LEFT:
            nextPos.y = currentPos.y;
            nextPos.x = currentPos.x - 1;
            break;
        case DOWN:
            nextPos.y = currentPos.y + 1;
            nextPos.x = currentPos.x;
            break;
        case RIGHT:
            nextPos.y = currentPos.y;
            nextPos.x = currentPos.x + 1;
            break;
        default: // Next position remains the same as current if direction = STOP
            break;
    }

    // Switch sides at boarder
    if(nextPos.x < 1)
    {
        nextPos.x = 30-2;
    }
    else if(nextPos.x > 30-2)
    {
        nextPos.x = 1;
    }

    if(nextPos.y < 1)
    {
        nextPos.y = 15-2;
    }
    else if(nextPos.y > 15-2)
    {
        nextPos.y = 1;
    }

    // Move to next position if different than the current position
    if ((nextPos.x == currentPos.x && nextPos.y == currentPos.y) == false)
    {
        playerPosList->insertHead(nextPos);
        playerPosList->removeTail();
    }
}