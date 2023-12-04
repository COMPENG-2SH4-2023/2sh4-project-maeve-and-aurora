#include "GameMechs.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0; 
    foodX = 5;
    foodY = 5;

    int i; 
    GameMechsD = new int*[15];
    for(i=0; i<15; i++)
    {
        GameMechsD[i] = new int[30]; 
    }
}

GameMechs::GameMechs(int boardX, int boardY)
{
    int i, j; 

    GameMechsD = new int*[15];
    for(i=0; i<15; i++)
    {
        GameMechsD[i] = new int[30]; 
    }

    reset(); 
    
}


GameMechs::~GameMechs() 
{
    int i=0; 

	for(i=0; i < 15; i++)
	{
		delete [] GameMechsD[i]; 
	}

	delete[] GameMechsD; 
}

bool GameMechs::GenerateFood(objPosArrayList &playerPosList)
{
    // Seed random with current time
    srand(time(NULL));

    // Get coordinates in game board range
    foodX = rand() % 27 + 1; //might have to play with ending nums
    foodY = rand() % 12 + 1;
    
    // Verify that the current position doesn't overlap the player
    int i;
    objPos temp;
    for( i=0; i < playerPosList.getSize(); i++)
    {
        playerPosList.getElement(temp, i);

        if ((foodX == temp.x) && (foodY == temp.y))
        {
            return false; 
        }        
    }

    return true; 
}

bool GameMechs::getExitFlagStatus()
{
    // Return exit flag value
    return exitFlag; 
}

bool GameMechs::getLoseFlagStatus()
{
    // Return lose flag value
    return loseFlag; 
}

int GameMechs::getBoardSizeX()
{
    // Return the x dimension of the game board
    return boardSizeX; 
}

int GameMechs::getBoardSizeY()
{
    // Return the y dimension of the game board
    return boardSizeY; 
}

void GameMechs::setExitTrue()
{
    // Set exit flag to true
    exitFlag = true; 
}

void GameMechs::setLoseTrue()
{
    // Set lose flag to true
    loseFlag = true; 
}

void GameMechs::setInput(char this_input)
{
    // Set input 
    input = this_input; 
}

char GameMechs::getInput()
{
    // Return input value
    return input; 
}

void GameMechs::clearInput()
{
    // Reset input to NULL
    input = 0; 
}

int GameMechs::getScore()
{
    // Return score value
    return score; 
}
void GameMechs::incScore(int inc)
{
    // Increase score value by one
    score = score + inc; 
}

int GameMechs::getGameMechsD(int i, int j)
{
    // Return symbol at given location
    return GameMechsD[i][j]; 
}

int GameMechs::getFoodX()
{
    // Return food x coordinate 
    return foodX; 
}

int GameMechs::getFoodY()
{
    // Return food y coordinate
    return foodY; 
}

void GameMechs::editBoard(int i, int j, int sym)
{
    // Set new symbol at given location
    GameMechsD[i][j] = sym; 
}

void GameMechs::reset() 
{
    int i, j; 

    for(i=0; i<15; i++)
    {
        for(j=0; j<30; j++)
        {
            if((i==0) || (i==14)|| (j==0) || (j==29))
            {
                GameMechsD[i][j] = '#';
            }
            else
            {
                GameMechsD[i][j] = ' '; 
            }
        }   
    }
}