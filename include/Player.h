#pragma once
#include"Unit.h"
#include<unordered_map>

enum typeOfUnit {infantryman, cavalryman, tank, armoredCar, artillery};

const int START_MONEY = 700; 

class Player {
private:
    int id;
    std::unordered_map<unsigned long long, Unit*> units;
    int money;
    bool hisTurn;
public:
    Player(int id = 0);
    bool isHisTurn();
    void buyUnit(typeOfUnit unit);
    ~Player();
};