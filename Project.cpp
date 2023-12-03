#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h" 
#include "Player.h" 


using namespace std;

#define DELAY_CONST 100000
//char message1[31] = "#                            #"; //For debuging, can be deleted

//Global Varible Declaration
//bool exitFlag; 

//Pointer Declaration
GameMechs* GameMechsPtr = nullptr; //game mechs pointer! There should be no other global varibles according to the manual
Player* player = nullptr;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
void genFoodGame(); 



int main(void)
{

    Initialize();

    while(GameMechsPtr -> getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    GameMechsPtr = new GameMechs(); 
    GameMechs(); 

    player = new Player(GameMechsPtr);

    genFoodGame(); 

}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        GameMechsPtr -> setInput(MacUILib_getChar()); 
    }

    int input = GameMechsPtr->getInput();

    if (input)
    {
        if (input == 27)
        {
            GameMechsPtr -> setExitTrue();
        }
        else
        {
            player -> updatePlayerDir();
        }
    }
   
   GameMechsPtr -> clearInput();
}

void RunLogic(void)
{
    // move player in current direction 
    player->movePlayer();

    // if food is eaten
    // GameMechsPtr -> incScore(1);

}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    int i; 
    int j;  
    int x = GameMechsPtr ->getX(); 
    int y = GameMechsPtr -> getY(); 
    
    int foodX = GameMechsPtr -> getFoodX(); 
    int foodY = GameMechsPtr -> getFoodY();
    objPos playerPositions;
    player->getPlayerPos(playerPositions);
    
    GameMechs a = GameMechs(foodX, foodY); 

    for(i = 0; i < 15; i++)
    {
        for(j = 0; j < 30; j++)
        {
            if (i == playerPositions.y && j == playerPositions.x)
            {
                a.editBoard(i, j, playerPositions.symbol);
            }
            else if (i == foodY && j == foodX)
            {
                a.editBoard(i, j, 'O');
            }
            cout << static_cast<char> (a.getGameMechsD(i, j)) ; 
        }
        cout << endl; 
    }

   cout << "Score: " << GameMechsPtr ->getScore() << endl; 

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();   
    delete GameMechsPtr; 
    delete player; 
  
    MacUILib_uninit();
}

void genFoodGame()
{
    bool foodgen; 

    do
    {
       foodgen = GameMechsPtr -> GenerateFood(); 
    }
    while(foodgen == false); 
    

}
