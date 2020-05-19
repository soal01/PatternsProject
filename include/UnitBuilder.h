#pragma once
#include"Unit.h"

class UnitBuilder {
private:
public:
    virtual void reset(int idOfNewUnit) = 0;
    virtual void setCost() = 0;
    virtual void setHealth() = 0;
    virtual void setDamage() = 0;
    virtual void setPointsOfMobility() = 0;
    virtual void setAttackRange() = 0;
    virtual void setImageOnPlayGround() = 0;
    virtual Unit* getResult() = 0;
};



class InfatrymanBuilder : public UnitBuilder {
private:
    Infantryman *result;
public:
    void reset(int idOfNewUnit) override;
    void setCost() override;
    void setHealth() override;
    void setDamage() override;
    void setPointsOfMobility() override;
    void setAttackRange() override;
    void setImageOnPlayGround() override;
    Infantryman* getResult() override;
};

class CavalrymanBuilder : public UnitBuilder {
private:
    Cavalryman *result;
public:
    void reset(int idOfNewUnit) override;
    void setCost() override;
    void setHealth() override;
    void setDamage() override;
    void setPointsOfMobility() override;
    void setAttackRange() override;
    void setImageOnPlayGround() override;
    Cavalryman* getResult() override;
};

class TankBuilder : public UnitBuilder {
private:
    Tank *result;
public:
    void reset(int idOfNewUnit) override;
    void setCost() override;
    void setHealth() override;
    void setDamage() override;
    void setPointsOfMobility() override;
    void setAttackRange() override;
    void setImageOnPlayGround() override;
    Tank* getResult() override;
};

class ArmoredCarBuilder : public UnitBuilder {
private:
    ArmoredCar *result;
public:
    void reset(int idOfNewUnit) override;
    void setCost() override;
    void setHealth() override;
    void setDamage() override;
    void setPointsOfMobility() override;
    void setAttackRange() override;
    void setImageOnPlayGround() override;
    ArmoredCar* getResult() override;
};


class ArtilleryBuilder : public UnitBuilder {
private:
    Artillery *result;
public:
    void reset(int idOfNewUnit) override;
    void setCost() override;
    void setHealth() override;
    void setDamage() override;
    void setPointsOfMobility() override;
    void setAttackRange() override;
    void setImageOnPlayGround() override;
    Artillery* getResult() override;
};
