#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>
#include <stdlib.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.
    
    private:
        char input;
        bool exitFlag= false;
        
        int boardSizeX =30;
        int boardSizeY =15;

        int x = 14; 
        int y =5; 
        int score=0; 

        int foodX;
        int foodY;

        int **GameMechsD; 

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); 
        
        bool getExitFlagStatus();
        void setExitTrue();
        //void setMessage(int pos, char input); 

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();

        int getX(); 
        int getY(); 
        char getMessage(int pos); 

        int getScore(); 
        void incScore(int inc); 

        int getGameMechsD(int i, int j); 

        int getFoodX(); 
        int getFoodY(); 
        
        bool GenerateFood(objPosArrayList &playerPosList); 

        void editBoard(int i, int j, int sym); 
};

#endif