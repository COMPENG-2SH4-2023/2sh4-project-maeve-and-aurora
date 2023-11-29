#include "GameMechs.h"

GameMechs::GameMechs()
{

}

GameMechs::GameMechs(int boardX, int boardY)
{

}

// do you need a destructor?

GameMechs::~GameMechs() 
{
    delete[] GameMechsD;
}



bool GameMechs::getExitFlagStatus()
{
    return(exitFlag); 

}

char GameMechs::getInput()
{
    return(input); 

}

int GameMechs::getBoardSizeX()
{

}

int GameMechs::getBoardSizeY()
{

}


void GameMechs::setExitTrue()
{
    exitFlag = true; 

}

void GameMechs::setInput(char this_input)
{
    input = this_input; 
}

void GameMechs::clearInput()
{

}


