#include "Player.h"
#include "GameMechs.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef -> getBoardSizeX()/2, mainGameMechsRef -> getBoardSizeY()/2, '*');

    playerPosList = new objPosArrayList();
    playerPosList -> insertHead(tempPos);
}


Player::~Player()
{
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // Return the reference to the playerPos arrray list
    return playerPosList;
}


void Player::updatePlayerDir()
{
    char input = mainGameMechsRef -> getInput();
    
    switch(input)
    {
        case 'w':
            if (myDir != UP && myDir != DOWN)
            {
                myDir = UP; // if W, moving up ONLY allowed if LEFT or RIGHT
            }
            break;

        case 'a':
            if (myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT; // if A, moving left ONLY allowed if UP or DOWN
            }
            break;

        case 's':
            if (myDir != UP && myDir != DOWN)
            {
                myDir = DOWN; // if S, moving down ONLY allowed if LEFT or RIGHT
            }
            break;

        case 'd':
            if (myDir != LEFT && myDir != RIGHT)
            {
                myDir = RIGHT; // if D, moving left ONLY allowed if UP or DOWN
            }
            break;
        
        default:
            break;
    }        
}

void Player::movePlayer()
{
    // Finite State Machine logic
    objPos currentHead; // Holds the position information of the current head
    objPos positionCheck;
    playerPosList -> getHeadElement(currentHead);
    
    switch (myDir)
    {
        case LEFT:
            currentHead.x--;
            break;
        
        case RIGHT:
            currentHead.x++;
            break;

        case UP:
            currentHead.y--;
            break;

        case DOWN:
            currentHead.y++;
            break;

        default:
            break;
    }

    // Wraparound logic for game board boundaries

    if (currentHead.x == 0)
    {
        currentHead.x = mainGameMechsRef -> getBoardSizeX() - 2;
    } 

    else if(currentHead.x == mainGameMechsRef -> getBoardSizeX() - 1)
    { 
        currentHead.x = 1;
    }

    else if(currentHead.y == 0)
    {
        currentHead.y = mainGameMechsRef -> getBoardSizeY() - 2;
    }

    else if(currentHead.y == mainGameMechsRef -> getBoardSizeY() - 1)
    {
        currentHead.y = 1;
    }

    for(int i = 1; i < playerPosList -> getSize(); i++)
    {
        playerPosList -> getElement(positionCheck, i);
        if(currentHead.isPosEqual(&positionCheck))
        {
            mainGameMechsRef -> setLoseTrue();
            mainGameMechsRef -> setExitTrue();
            break;
        }
    }

    // Check if newly positioned head overlaps with objPos of food
    objPos foodPosition;
    
    mainGameMechsRef -> getFoodPos(foodPosition);

    if (currentHead.isPosEqual(&foodPosition)) // If match, insert head but DO NOT remove tail
    {
        playerPosList -> insertHead(currentHead); // Increments snake length by 1

        mainGameMechsRef -> incrementScore();
        mainGameMechsRef -> generateFood(playerPosList);
    }

    else // If no, carry out regular insert and removal
    {
    // New current head should be inserted into the head of the list.
    playerPosList -> insertHead(currentHead);

    // Then, remove tail.
    playerPosList -> removeTail();
    }
}