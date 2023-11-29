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
    return(boardSizeX); 
}

int GameMechs::getBoardSizeY()
{
    return(boardSizeY); 
}


void GameMechs::setExitTrue()
{
    exitFlag = true; 

}

int GameMechs::getX()
{
    int x=5; 
    return(x); 

}

int GameMechs::getY()
{
    int y=5;
    return(y);  

}

char GameMechs::getMessage(int pos)
{
   return(message[pos]);  

}

void GameMechs::setInput(char this_input)
{
    input = this_input; 
}

void GameMechs::clearInput()
{
    input = 0; 
}


