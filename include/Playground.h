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
    std::string _info;
    std::string _error;
    
    Playground();
    void initializePlayers();
    void initializeCells();
    void deletePlayers();
    void deleteCells();
    static Playground* mainPlayground;
    
    void printMap();
    //void printInfo(Coordinates coordinates);
    //std::string getErrors();

public:
    static Playground* getInstance();
    void deleteInstance();
    std::string getInfoAboutCell(Coordinates coordinates);
    void setInfo(std::string newInfo);
    void setError(std::string newError);
    bool isCorrectMove(Coordinates from, Coordinates to);
    bool isAttackMove(Coordinates from, Coordinates to);
    void moveUnit(Coordinates from, Coordinates to);
    void calculateAttack(Unit* attacker, Terrain* terrainOfAttacker,
                        Unit* defender, Terrain* terrainOfDefender);

    void print();
    bool isEndOfGame();
    void setUnitOnPlayground(Coordinates coordinates, TypeOfUnit typeOfUnit);
    ~Playground();
};
