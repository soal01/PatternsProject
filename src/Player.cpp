#include"Player.h"
#include<iostream>

Player::Player(int id): _id(id), _money(START_MONEY), _hisTurn(false) {}

Player::~Player() {
    for (auto x: units) {
        delete x.second;
    }
}

Unit* Player::buyUnit(MainBuilder& builder, TypeOfUnit typeOfUnit) {
    UnitBuilder* unitBuilder = nullptr;
    if (typeOfUnit == TypeOfUnit::infantryman) {
        unitBuilder = new InfatrymanBuilder();
    }
    if (typeOfUnit == TypeOfUnit::cavalryman) {
        unitBuilder = new CavalrymanBuilder();
    }
    if (typeOfUnit == TypeOfUnit::tank) {
        unitBuilder = new TankBuilder();
    }
    if (typeOfUnit == TypeOfUnit::armoredCar) {
        unitBuilder = new ArmoredCarBuilder();
    }
    if (typeOfUnit == TypeOfUnit::artillery) {
        unitBuilder = new ArtilleryBuilder();
    }
    Unit* newUnit = builder.buildUnit(unitBuilder);
    _money -= newUnit->getCost();
    units[newUnit->getId()] = newUnit;
    return newUnit;
}

size_t Player::countOfUnits() {
    return units.size();
}

int Player::getMoney() {
    return _money;
}

void Player::destroyUnit(unsigned long long id) {
    delete units[id];
}

void Player::damageUnit(unsigned long long id, double damage) {
    units[id]->setHealth(units[id]->getHealth() - damage);
}

void Player::decreaseMovePointsOfUnit(unsigned long long id, double delta) {
    units[id]->setPointsOfMobility(units[id]->getPointsOfMobility() - delta);
}

void Player::nextTurn() {
    _money += 50;
    for (auto& unit: units) {
        unit.second->heal();
        unit.second->recoveryOfPointOfMobility();
    }
}