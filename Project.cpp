#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"; //This wasnt included in the original skeleton code but I don't see 
                        //any way this will work without it? We need a pointer to game mechs
                        //and I dont think thats possible without including this library  


using namespace std;

#define DELAY_CONST 100000

//Global Varible Declaration
//bool exitFlag; 

//Pointer Declaration
GameMechs* GameMechsPtr = nullptr; //game mechs pointer! There should be no other global varibles according to the manual

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(GameMechsPtr -> exitFlag == false)  
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
    GameMechsPtr = new; 
    GameMechs(); 

    GameMechsPtr -> exitFlag = false;
    cout << "Hej"; 
}

void GetInput(void)
{
   if (MacUILib_hasChar())
    {
        GameMechsPtr -> input= MacUILib_getChar(); 
    }
}

void RunLogic(void)
{
    if(GameMechsPtr -> input != 0)
    {
        switch(GameMechsPtr -> input)
        {
            case 27:
                GameMechsPtr -> input = 1; 
                break; 
        }
    }
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();   
    delete GameMechsPtr;  
  
    MacUILib_uninit();
}
