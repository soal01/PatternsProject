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