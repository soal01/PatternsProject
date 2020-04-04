#pragma once
#include"Coordinates.h"

enum TypeOfUnit {infantryman, cavalryman, tank, armoredCar, artillery};

class Unit {
private:

protected:
    unsigned long long _id;
    int _cost;
    double _health;
    double _damage;
    double _pointsOfMobility;
    Coordinates _coordinates;
    int _playerId;
    int _attackRange; 
    char _imageOnPlaygroud;
    
public: 
    virtual void setId(unsigned long long id);
    virtual void setCost(int cost);
    virtual void setHealth(double health);
    virtual void setDamage(double damage);
    virtual void setPointsOfMobility(double pointsOfMobility);
    virtual void setPositionOfUnit(Coordinates coordinates);
    virtual void setPlayerId(int playerId);
    virtual void setAttackRange(int attackRange);
    virtual void setImageOnPlayground(char imageOnPlayground);
    virtual char getImageOnPlayGround();
    virtual unsigned long long getId();
    virtual int getCost();
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


