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

    genFoodGame(); 

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
        GameMechsPtr -> incScore(1); //this might need to move once the WASD move keys are implemented
        switch(input)
        {
            case 27:
                GameMechsPtr -> setExitTrue(); 
                break; 
//FOR TESTING ONLY
            // case 'a':
            //     genFoodGame(); 
            //     break; 

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
    
    int foodX = GameMechsPtr -> getFoodX(); 
    int foodY = GameMechsPtr -> getFoodY(); 

    GameMechs a = GameMechs(foodX, foodY); 

    for(i = 0; i < 15; i++)
    {
        for(j = 0; j < 30; j++)
        {
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
