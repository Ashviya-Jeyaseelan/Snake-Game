#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

// Preprocessor constants & global variable definition
///////////////////////////////////////////////////////
#define escapeKey 32 // Spacebar for escaping the game

GameMechs * myGameMech;
Player * myPlayer;

objPos tempPos;
objPos food;
objPosArrayList* playerList;
///////////////////////////////////////////////////////

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{
    Initialize();

    // Loop continues as long as exit flag in GameMechs is false
    while(myGameMech -> getExitFlagStatus() == false) 
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

    myGameMech = new GameMechs(30, 15); // Creates the board size 30 x 15
    myPlayer = new Player(myGameMech); // Creates new player object

    playerList = myPlayer -> getPlayerPos();
    myGameMech -> generateFood(playerList); // Randomly generates food on the board
}


void GetInput(void)
{
   myGameMech -> setInput(myGameMech -> getInput()); // Obtain input from GameMechs
}

void RunLogic(void)
{
    if (myGameMech -> getInput() == escapeKey) // Exits game is spacebar is inputted
    {
        myGameMech -> setExitTrue(); 
    }

    myPlayer -> updatePlayerDir();
    myPlayer -> movePlayer();

    myGameMech -> clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPosArrayList* playerBody = myPlayer -> getPlayerPos();
    objPos tempBody;

    bool drawn;

    myGameMech -> getFoodPos(food);
    
    for (int i = 0; i < myGameMech -> getBoardSizeY(); i++) // Iterates through all rows
    {
        for (int j = 0; j < myGameMech -> getBoardSizeX(); j++) // Iterates through all columns
        {
            drawn = false;
            
            // Iterate through every single element in the playerBody list
            for (int k = 0; k < playerBody -> getSize(); k++)
            {
                playerBody -> getElement(tempBody, k);
                if (tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn) continue;
            // If player body was drawn, don't draw anything below

            if(i == 0 || i == myGameMech -> getBoardSizeY() - 1 || j == 0 || j == myGameMech -> getBoardSizeX() - 1) // Add frame for first and last row
            {
                MacUILib_printf("#");
            }

            else
            {
                int spaceTaken = 0;
                if(i == food.y && j == food.x) // Prints food if the current indices match food coordinates
                {
                    MacUILib_printf("%c",food.symbol);
                    spaceTaken = 1;
                }
                if(spaceTaken == 0) // If it isn't taken by the food, print the space
                {
                    MacUILib_printf(" ");
                }  
            }
        }
        MacUILib_printf("\n");
    }


    MacUILib_printf("Instructions: Move the player object with the WASD keys. Click space to exit game.\n");
    MacUILib_printf("\n");
    MacUILib_printf("Board Size: %d x %d\n", myGameMech -> getBoardSizeX(), myGameMech -> getBoardSizeY());
    MacUILib_printf("----------\n");
    
    MacUILib_printf("Your score: %d", myGameMech -> getScore());
    MacUILib_printf("\n");

    MacUILib_printf("Food Position: <%d, %d>",food.x, food.y);
}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();

    if(myGameMech -> getLoseFlagStatus() == true)
    {
        MacUILib_printf("Game Over - You lost. Your score is %d", myGameMech -> getScore());
    }
    else
    {
        MacUILib_printf("Well done! Your score is %d", myGameMech -> getScore());
    }

    MacUILib_uninit();
    
    delete myGameMech;
    delete myPlayer;
}
