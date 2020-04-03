#pragma once
#include"Cell.h"
#include"string"

class Playground {
private:
    static const unsigned COUNT_OF_PLAYERS = 2;
    static const unsigned SIZE_OF_PLAYGROUND = 20;
    Cell cells[SIZE_OF_PLAYGROUND][SIZE_OF_PLAYGROUND];
    //std::string mapIn

    static Playground* playground;
public:
    void printMap();
};