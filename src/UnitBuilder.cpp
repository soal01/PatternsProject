#include"../include/UnitBuilder.h"

void InfatrymanBuilder::reset(int idOfNewUnit) {
    result = new Infantryman();
    result->setId(idOfNewUnit);
}

void InfatrymanBuilder::setCost() {
    result->setCost(DefaultInfatrymanStats::cost);
}

void InfatrymanBuilder::setHealth() {
    result->setHealth(DefaultInfatrymanStats::health);
}

void InfatrymanBuilder::setDamage() {
    result->setDamage(DefaultInfatrymanStats::damage);
}

void InfatrymanBuilder::setPointsOfMobility() {
    result->setPointsOfMobility(DefaultInfatrymanStats::pointsOfMobility);
}

void InfatrymanBuilder::setAttackRange() {
    result->setAttackRange(DefaultInfatrymanStats::attackRange);
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
    result->setCost(DefaultCavalrymanStats::cost);
}

void CavalrymanBuilder::setHealth() {
    result->setHealth(DefaultCavalrymanStats::health);
}

void CavalrymanBuilder::setDamage() {
    result->setDamage(DefaultCavalrymanStats::damage);
}

void CavalrymanBuilder::setPointsOfMobility() {
    result->setPointsOfMobility(DefaultCavalrymanStats::pointsOfMobility);
}

void CavalrymanBuilder::setAttackRange() {
    result->setAttackRange(DefaultCavalrymanStats::attackRange);
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
    result->setCost(DefaultTankStats::cost);
}

void TankBuilder::setHealth() {
    result->setHealth(DefaultTankStats::health);
}

void TankBuilder::setDamage() {
    result->setDamage(DefaultTankStats::damage);
}

void TankBuilder::setPointsOfMobility() {
    result->setPointsOfMobility(DefaultTankStats::pointsOfMobility);
}

void TankBuilder::setAttackRange() {
    result->setAttackRange(DefaultTankStats::attackRange);
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
    result->setCost(DefaultArmoredCarStats::cost);
}

void ArmoredCarBuilder::setHealth() {
    result->setHealth(DefaultArmoredCarStats::health);
}

void ArmoredCarBuilder::setDamage() {
    result->setDamage(DefaultArmoredCarStats::damage);
}

void ArmoredCarBuilder::setPointsOfMobility() {
    result->setPointsOfMobility(DefaultArmoredCarStats::pointsOfMobility);
}

void ArmoredCarBuilder::setAttackRange() {
    result->setAttackRange(DefaultArmoredCarStats::attackRange);
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
    result->setCost(DefaultArtilleryStats::cost);
}

void ArtilleryBuilder::setHealth() {
    result->setHealth(DefaultArtilleryStats::health);
}

void ArtilleryBuilder::setDamage() {
    result->setDamage(DefaultArtilleryStats::damage);
}

void ArtilleryBuilder::setPointsOfMobility() {
    result->setPointsOfMobility(DefaultArtilleryStats::attackRange);
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