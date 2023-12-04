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
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score; 

        int **GameMechsD; // Double pointer which stores the ASCII integers of the characters who make up the game board

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); 
        
        bool getExitFlagStatus();
        void setExitTrue();

        bool getLoseFlagStatus();
        void setLoseTrue(); 

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getScore(); 
        void incScore(int inc); 

        int getGameMechsD(int i, int j); // Get the ASCII integer stored at a specific address
        void allocateMem(int i, int j); // Allocate memory for the GameMechsD pointer

        void editBoard(int i, int j, int sym); // Place a specific ASCII integer at a specific address
        void reset();  // Reset the board to blank
};

#endif