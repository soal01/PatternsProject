#pragma once
#include"Unit.h"
#include"MainBuilder.h"
#include<unordered_map>


const int START_MONEY = 700; 

class Player {
private:
    int _id;
    std::unordered_map<unsigned long long, Unit*> units;
    int _money;
    bool _hisTurn;
public:
    Player(int id = 0);
    bool isHisTurn();
    Unit* buyUnit(MainBuilder& builder, TypeOfUnit typeOfUnit);
    ~Player();
};