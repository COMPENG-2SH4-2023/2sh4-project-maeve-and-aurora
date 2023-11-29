#include "GameMechs.h"

GameMechs::GameMechs()
{

}

GameMechs::GameMechs(int boardX, int boardY)
{
    int i; 


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
    return(x); 

}

int GameMechs::getY()
{
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

void GameMechs::setMessage(int pos, char input)
{
    message[pos] = input; 
}


