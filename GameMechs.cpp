#include "GameMechs.h"

GameMechs::GameMechs()
{
    //unused constructor
}

GameMechs::GameMechs(int boardX, int boardY)
{
    int i; 
    GameMechsD = new int[30];
    GameMechsD[0] = 35; //ASCII #
    for (i = 1; i<29; i++) //just picked 29 becuase thats the length of the board -1. Assuming we
    {                        // aren't changing the size of the board
        if (i == boardX)
        {
            GameMechsD[i] = 79; //ASCII O
        }

        else
        {
            GameMechsD[i] = 32; //ASCII space
        }
    }

    GameMechsD[29] = 35; //ASCII #


}


GameMechs::~GameMechs() 
{
    delete[] GameMechsD;
}

bool GameMechs::GenerateFood()
{
    srand(time(0));

    foodX = rand() % 27 + 1; //might have to play with ending nums
    foodY = rand() % 12 + 1;

    if ((foodX == x) && (foodY == y))
    {
        return(false); 
    }

    else
    {
        return(true); 
    }
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


int GameMechs::getScore()
{
    
    return(score); 
}
void GameMechs::incScore(int inc)
{
    score = score + inc; 

}

int* GameMechs::getGameMechsD()
{
    return GameMechsD; 
}

// void GameMechs::setMessage(int pos, char input)
// {
//     message[pos] = input; 
// }

int GameMechs::getFoodX()
{
    return(foodX); 
}

int GameMechs::getFoodY()
{
    return(foodY); 
}

