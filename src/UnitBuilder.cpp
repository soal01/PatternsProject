#include"../include/UnitBuilder.h"

void InfatrymanBuilder::reset(int idOfNewUnit) {
    result = new Infantryman();
    result->setId(idOfNewUnit);
}

void InfatrymanBuilder::setCost() {
    result->setCost(50);
}

void InfatrymanBuilder::setHealth() {
    result->setHealth(75);
}

void InfatrymanBuilder::setDamage() {
    result->setDamage(8);
}

void InfatrymanBuilder::setPointsOfMobility() {
    result->setPointsOfMobility(4);
}

void InfatrymanBuilder::setAttackRange() {
    result->setAttackRange(1);
}

void InfatrymanBuilder::setImageOnPlayGround() {
    result->setImageOnPlayground('S');
}

Infantryman* InfatrymanBuilder::getResult() {
    return result;
}


void CavalrymanBuilder::reset(int idOfNewUnit) {
    result = new Cavalryman();
    result->setId(idOfNewUnit);
}

void CavalrymanBuilder::setCost() {
    result->setCost(75);
}

void CavalrymanBuilder::setHealth() {
    result->setHealth(100);
}

void CavalrymanBuilder::setDamage() {
    result->setDamage(7);
}

void CavalrymanBuilder::setPointsOfMobility() {
    result->setPointsOfMobility(8);
}

void CavalrymanBuilder::setAttackRange() {
    result->setAttackRange(1);
}

void CavalrymanBuilder::setImageOnPlayGround() {
    result->setImageOnPlayground('C');
}

Cavalryman* CavalrymanBuilder::getResult() {
    return result;
}


void TankBuilder::reset(int idOfNewUnit) {
    result = new Tank();
    result->setId(idOfNewUnit);
}

void TankBuilder::setCost() {
    result->setCost(200);
}

void TankBuilder::setHealth() {
    result->setHealth(200);
}

void TankBuilder::setDamage() {
    result->setDamage(16);
}

void TankBuilder::setPointsOfMobility() {
    result->setPointsOfMobility(5);
}

void TankBuilder::setAttackRange() {
    result->setAttackRange(1);
}

void TankBuilder::setImageOnPlayGround() {
    result->setImageOnPlayground('T');
}

Tank* TankBuilder::getResult() {
    return result;
}


void ArmoredCarBuilder::reset(int idOfNewUnit) {
    result = new ArmoredCar();
    result->setId(idOfNewUnit);
}

void ArmoredCarBuilder::setCost() {
    result->setCost(100);
}

void ArmoredCarBuilder::setHealth() {
    result->setHealth(130);
}

void ArmoredCarBuilder::setDamage() {
    result->setDamage(10);
}

void ArmoredCarBuilder::setPointsOfMobility() {
    result->setPointsOfMobility(6);
}

void ArmoredCarBuilder::setAttackRange() {
    result->setAttackRange(1);
}

void ArmoredCarBuilder::setImageOnPlayGround() {
    result->setImageOnPlayground('B');
}

ArmoredCar* ArmoredCarBuilder::getResult() {
    return result;
}


void ArtilleryBuilder::reset(int idOfNewUnit) {
    result = new Artillery();
    result->setId(idOfNewUnit);
}

void ArtilleryBuilder::setCost() {
    result->setCost(140);
}

void ArtilleryBuilder::setHealth() {
    result->setHealth(80);
}

void ArtilleryBuilder::setDamage() {
    result->setDamage(15);
}

void ArtilleryBuilder::setPointsOfMobility() {
    result->setPointsOfMobility(2);
}

void ArtilleryBuilder::setAttackRange() {
    result->setAttackRange(2);
}

void ArtilleryBuilder::setImageOnPlayGround() {
    result->setImageOnPlayground('A');
}

Artillery* ArtilleryBuilder::getResult() {
    return result;
}