#pragma once
#include"Coordinates.h"
#include<string>

enum TypeOfUnit {infantryman, cavalryman, tank, armoredCar, artillery};
TypeOfUnit convertToTypeOfUnit(int type);


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
    virtual double getHealth();
    virtual int getPointsOfMobility();
    virtual int getPlayerId();
    virtual int getAttackRange();
    virtual double getDamage();
    virtual void heal() = 0;
    virtual void recoveryOfPointOfMobility() = 0;
};


class Infantryman : public Unit {
private:

public:
    Infantryman();
    void heal() override;
    void recoveryOfPointOfMobility() override;
};

class Cavalryman : public Unit {
private:

public:
    Cavalryman();
    void heal() override;
    void recoveryOfPointOfMobility() override;
};

class Tank : public Unit {
private:

public:
    Tank();
    void heal() override;
    void recoveryOfPointOfMobility() override;
};

class ArmoredCar : public Unit {
private:

public:
    ArmoredCar();
    void heal() override;
    void recoveryOfPointOfMobility() override;
};

class Artillery : public Unit {
private:

public: 
    Artillery();
    void heal() override;
    void recoveryOfPointOfMobility() override;
};


std::string getTypeOfUnit(Unit* unit);

class DefaultInfatrymanStats {
public:
    static const int cost = 50;
    constexpr static const double health = 75.;
    constexpr static const double damage = 23.;
    constexpr static const double pointsOfMobility = 4.;
    static const int attackRange = 1;
};

struct DefaultCavalrymanStats {
    static const int cost = 75;
    constexpr static const double health = 100.;
    constexpr static const double damage = 35.;
    constexpr static const double pointsOfMobility = 8.;
    static const int attackRange = 1.;
};

struct DefaultTankStats {
    static const int cost = 200;
    constexpr static const double health = 200.;
    constexpr static const double damage = 80.;
    constexpr static const double pointsOfMobility = 5.;
    static const int attackRange = 1;
};

struct DefaultArmoredCarStats {
    static const int cost = 100;
    constexpr static const double health = 130.;
    constexpr static const double damage = 45.;
    constexpr static const double pointsOfMobility = 6.;
    static const int attackRange = 1;
};

struct DefaultArtilleryStats {
    static const int cost = 140;
    constexpr static const double health = 80.;
    constexpr static const double damage = 60.;
    constexpr static const double pointsOfMobility = 2.;
    static const int attackRange = 2;
};
