#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h" //This wasnt included in the original skeleton code but I don't see 
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
    

   //GameMechsPtr -> getExitFlagStatus() 

    
}

void GetInput(void)
{
   if (MacUILib_hasChar())
    {
        GameMechsPtr -> setInput(MacUILib_getChar()); 
    }
}

void RunLogic(void)
{
    char input = GameMechsPtr -> getInput(); 
    int x = 5; 
    int y = 5; 

    
    
    if(input != 0)
    {
        switch(input)
        {
            case 27:
                GameMechsPtr -> setExitTrue(); 
                break; 

            default:
                break; 
        }

        GameMechsPtr -> clearInput(); 
    }

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    int i; 
    int j;  
    int x = GameMechsPtr ->getX(); 
    int y = GameMechsPtr -> getY(); 

    printf("####################\n"); 

    for (i=0; i<=7; i++)
    {
        if (i == y)
        {
            for (j=0; j<20; j++)
            {
                cout << GameMechsPtr -> getMessage(j); 
            }

            printf("\n"); 
        }

        else 
        {
            printf("#                  #\n"); 
        }
    }
    
   printf("####################\n"); 


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
