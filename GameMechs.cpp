#include "GameMechs.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0; 

    allocateMem(30, 15); 
    reset(); 
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    allocateMem(boardX, boardY); 
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

void GameMechs::allocateMem(int boardX, int boardY)
{
    int i; 

    GameMechsD = new int*[boardY];
    for(i=0; i<boardY; i++)
    {
        GameMechsD[i] = new int[boardX]; 
    }
}

void GameMechs::incScore(int inc)
{
    // Increase score value by one
    score = score + inc; 
}

void GameMechs::editBoard(int i, int j, int sym)
{
    // Set new symbol at given location
    GameMechsD[i][j] = sym; 
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

void GameMechs::clearInput()
{
    // Reset input to NULL
    input = 0; 
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

char GameMechs::getInput()
{
    // Return input value
    return input; 
}

int GameMechs::getScore()
{
    // Return score value
    return score; 
}

int GameMechs::getGameMechsD(int i, int j)
{
    // Return symbol at given location
    return GameMechsD[i][j]; 
}