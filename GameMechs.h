#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

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
        
        int boardSizeX;
        int boardSizeY;

        objPos foodPos;

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

        int getBoardSizeX();
        int getBoardSizeY();

        int getScore();
        void incrementScore();

        void generateFood(objPosArrayList* blockOffList);
        
        void getFoodPos(objPos &returnPos);
};

#endif