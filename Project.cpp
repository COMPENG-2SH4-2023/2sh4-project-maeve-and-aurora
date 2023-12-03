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


class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();

    private:
        objPos playerPos;   // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(15,7,'*');

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 
    char input = mainGameMechsRef -> getInput(); 

    switch(input)
    {              
        case 'w':  // up
            if(myDir == STOP || myDir == LEFT || myDir == RIGHT)
            {
                myDir = UP;
            }
            break;
        case 'a':  // left
            if(myDir == STOP || myDir == UP || myDir == DOWN)
            {
                myDir = LEFT;
            }
            break;
        case 's':  // down
            if(myDir == STOP || myDir == LEFT || myDir == RIGHT)
            {
                myDir = DOWN;
            }
            break;
        case 'd':  // right
            if(myDir == STOP || myDir == UP || myDir == DOWN)
            {
                myDir = RIGHT;
            }
            break;
        default:
            break;
    }      
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(myDir)
    {
        case UP:
            playerPos.y--;
            break;
        case LEFT:
            playerPos.x--;
            break;
        case DOWN:
            playerPos.y++;
            break;
        case RIGHT:
            playerPos.x++;
            break;
        default:
            break;
    }

    int boardSizeX = mainGameMechsRef -> getBoardSizeX();
    int boardSizeY = mainGameMechsRef -> getBoardSizeY();

    if(playerPos.x < 1)
    {
        playerPos.x = boardSizeX-2;
    }
    else if(playerPos.x > boardSizeX-2)
    {
        playerPos.x = 1;
    }

    if(playerPos.y < 1)
    {
        playerPos.y = boardSizeY-2;
    }
    else if(playerPos.y > boardSizeY-2)
    {
        playerPos.y = 1;
    }
}

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
   cout << playerPositions.x << endl;
   cout << playerPositions.y << endl;

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
