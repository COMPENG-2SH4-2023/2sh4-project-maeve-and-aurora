#include "GameMechs.h"

GameMechs::GameMechs()
{
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    int i, j; 

    GameMechsD = new int*[15];
    for(i=0; i<15; i++)
    {
        GameMechsD[i] = new int[30]; 
    }

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


GameMechs::~GameMechs() 
{
    int i=0; 

	for(i=0; i<5; i++)
	{
		delete[] GameMechsD[i]; 
	}

	delete[] GameMechsD; 
}

bool GameMechs::GenerateFood(objPosArrayList &playerPosList)
{
    srand(time(NULL));

    foodX = rand() % 27 + 1; //might have to play with ending nums
    foodY = rand() % 12 + 1;
    
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
    return(exitFlag); 
}

bool GameMechs::getLoseFlagStatus()
{
    return(loseFlag); 
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

void GameMechs::setLoseTrue()
{
    loseFlag = true; 
}

int GameMechs::getX()
{
    return(x); 
}

int GameMechs::getY()
{
    return(y);  
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

int GameMechs::getGameMechsD(int i, int j)
{
    return GameMechsD[i][j]; 
}

int GameMechs::getFoodX()
{
    return(foodX); 
}

int GameMechs::getFoodY()
{
    return(foodY); 
}

void GameMechs::editBoard(int i, int j, int sym)
{

    GameMechsD[i][j] = sym; 

}