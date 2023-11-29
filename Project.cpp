#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h" //This wasnt included in the original skeleton code but I don't see 
                        //any way this will work without it? We need a pointer to game mechs
                        //and I dont think thats possible without including this library  


using namespace std;

#define DELAY_CONST 100000
//char message1[31] = "#                            #"; //For debuging, can be deleted

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
    int x = GameMechsPtr -> getX(); 
    int y = GameMechsPtr -> getY(); 

    
    
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
   GameMechs a = GameMechs(x, y); 

    for (i = 1; i<29; i++) //just picked 29 becuase thats the length of the board -2. Assuming we
    {                        // aren't changing the size of the board
        if (i == x)
        {
            GameMechsPtr -> setMessage(i, '*');
        }

        else
        {
            GameMechsPtr -> setMessage(i, ' ');
        }
    }

    printf("##############################\n"); 

    for (i=0; i<14-1; i++)
    {
        if (i == y)
        {
            for (j=0; j<30; j++)
            {
                cout << GameMechsPtr -> getMessage(j); 
               // cout << "11111111111111111111111111111111111111"; 
            }

            printf("\n"); 
        }

        else 
        {
            printf("#                            #\n"); 
        }
    }
    
   printf("##############################\n"); 


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
