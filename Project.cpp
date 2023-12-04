#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h" 
#include "Player.h" 
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

//Global Varible Declaration
objPosArrayList playerPositions; // Seg Faults if created new in DrawScreen()
GameMechs a = GameMechs(0, 0); // Generate new clear board

//Pointer Declaration
GameMechs* GameMechsPtr = nullptr; 
Player* playerPtr = nullptr;
//Food* foodPtr = nullptr;

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

    // Allocate/Initialize global variables
    GameMechsPtr = new GameMechs(); 
    //foodPtr = new Food();
    playerPtr = new Player(GameMechsPtr); //, foodPtr
    playerPtr->getPlayerPos(playerPositions);

    // Generate first food item
    genFoodGame(); 
}

void GetInput(void)
{
    // Check input value
    if (MacUILib_hasChar())
    {
        GameMechsPtr -> setInput(MacUILib_getChar()); 
    }

    int input = GameMechsPtr->getInput();

    if (input)
    {
        if (input == ' ') // Exit with spacebar 
        {
            GameMechsPtr->setExitTrue();
        }
        else
        {
            playerPtr->updatePlayerDir();
        }
    }
   
   GameMechsPtr -> clearInput();
}

void RunLogic(void)
{
    // Move player in current direction, checking for collisions
    playerPtr->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    int i, j, k;
    
    int foodX = GameMechsPtr -> getFoodX(); // Get current food position
    int foodY = GameMechsPtr -> getFoodY();
    
    playerPtr->getPlayerPos(playerPositions); // Get current snake positions

    GameMechsPtr -> reset();

    objPos temp;

    for(i = 0; i < 15; i++)
    {
        for(j = 0; j < 30; j++)
        {
            // Check position for food 
            if (i == foodY && j == foodX)
            {
                GameMechsPtr->editBoard(i, j, 'O'); // Add to board
            }

            // Check position for snake
            for(k=0; k < playerPositions.getSize(); k++)
            {
                playerPositions.getElement(temp, k);

                if (i == temp.y && j == temp.x) // Check each part of the snake
                {
                    GameMechsPtr->editBoard(i, j, temp.symbol); // Add to board
                }
            }

            cout << static_cast<char> (GameMechsPtr->getGameMechsD(i, j)) ; // Print appropriate symbol
        }
        cout << endl; 
    }

    cout << "Score: " << GameMechsPtr ->getScore() << endl; // Print current score
    cout << "Exit with SPACE" << endl;
    
    if(GameMechsPtr->getLoseFlagStatus())
    {
        cout << "You lose! Score: " << GameMechsPtr ->getScore() << endl; // Print lose message
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{  
    // Deallocate global pointers
    delete GameMechsPtr; 
    //delete foodPtr;
    delete playerPtr; 
  
    MacUILib_uninit();
}

void genFoodGame()
{
    // Generate food item that doesn't overlap player position
    bool foodgen; 
    playerPtr->getPlayerPos(playerPositions);

    do
    {
       foodgen = GameMechsPtr -> GenerateFood(playerPositions); 
    }
    while(foodgen == false); 
}