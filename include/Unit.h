#pragma once
#include"Coordinates.h"
#include"Cell.h"

class Unit {
private:

protected:
    unsigned long long id;
    double health;
    double damage;
    double pointsOfMobility;
    //Coordinates coordinates;
    Cell* positionOfUnit;
    int atackRange; 
public:    
};


class Infantryman : public Unit {
private:

public:
    Infantryman();
};

class Cavalryman : public Unit {
private:

public:
    Cavalryman();
};

class Tank : public Unit {
private:

public:
    Tank();
};

class ArmoredCar : public Unit {
private:

public:
    ArmoredCar();
};

class Artillery : public Unit {
private:

public: 
    Artillery();
};
