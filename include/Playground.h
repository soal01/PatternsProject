#pragma once
#include"Cell.h"
#include"string"
#include"Player.h"
#include"MainBuilder.h"

class Playground {
private:
    MainBuilder builder;
    static const unsigned COUNT_OF_PLAYERS = 2;
    static const unsigned SIZE_OF_PLAYGROUND = 20;
    Cell* _cells[SIZE_OF_PLAYGROUND][SIZE_OF_PLAYGROUND];
    Player _players[2];
    unsigned numberOfActivePlayer;
    
    Playground();
    void initializePlayers();
    void initializeCells();
    void deletePlayers();
    void deleteCells();
    static Playground* mainPlayground;
    
public:
    static Playground* getInstance();
    void deleteInstance();
    void printMap();
    void setUnitOnPlayground(Coordinates coordinates, TypeOfUnit typeOfUnit);
    ~Playground();
};
