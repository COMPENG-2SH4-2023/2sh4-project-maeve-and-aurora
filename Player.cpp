#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* foodBinRef)
{
    mainGameMechsRef = thisGMRef;
    mainFoodBinRef = foodBinRef;
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

    // Calculate next position in current direction
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

    // Check for self collision
    checkSelfCollision(nextPos.x, nextPos.y);

    // Start movement to next position
    playerPosList->insertHead(nextPos);

    // Check for collision with food, false if index > list length
    int collisionIndex = checkFoodConsumption();

    // Apply collision conditions
    if (collisionIndex != 10)
    {
        char symbol;
        mainFoodBinRef->getSymbol(symbol, collisionIndex);

        switch(symbol)
        {
            case 'O':
                mainGameMechsRef->incScore(1);  
                break;
            case 'X':
                mainGameMechsRef->incScore(10);
                break;
            case 'I':
                playerPosList->removeTail(); // Remove once to finish current movement

                // Reduce length by 1 as long as the snake is longer than one piece
                if(playerPosList->getSize() > 1) 
                { 
                    playerPosList->removeTail(); 
                } 
                
                break;
            default:
                break;
        }

        // Replace collided food item
        mainFoodBinRef->GenerateFood(*playerPosList, collisionIndex);
    }
    else
    {
        playerPosList->removeTail(); // Finish full movement since food not collected/length not added
    }
}

int Player::checkFoodConsumption()
{
    int i;
    objPosArrayList* foodPositions;
    objPos head, food;
    mainFoodBinRef->getFoodPos(*foodPositions);
    playerPosList->getHeadElement(head);

    for(i=0; i < 5; i++)
    {
        foodPositions->getElement(food, i);

        if (head.x == food.x && head.y == food.y) // Check all 5 food items
        {
            return i; // If hit any food, return index
        }
    }

    return 10; // Otherwise will return greater than list size
}

void Player::checkSelfCollision(int x, int y)
{
    int i;
    objPos body;

    for( i=1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(body, i);

        if (x == body.x && y == body.y)
        {
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseTrue();
        }
    }
}