#ifndef OBJPOS_H
#define OBJPOS_H

class objPos // Not very well designed, but serves the purpose. Advanced version of struct in PPA2.
{
    public:
        int x;
        int y;
        char symbol; // Can be accessed publicly

        objPos();
        objPos(objPos &o); // copy constructor
        objPos(int xPos, int yPos, char sym); // Specialized constructor

        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  
        void getObjPos(objPos &returnPos); // Pass by ref: You need to provide an empty objPos into this functio
        char getSymbol();                  // Then the objPos instance will write its own x, y, sym

        bool isPosEqual(const objPos* refPos); // Pass by pointer
        
        char getSymbolIfPosEqual(const objPos* refPos); // Pass by pointer
};

#endif