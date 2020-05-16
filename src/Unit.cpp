#include"../include/Unit.h"

TypeOfUnit convertToTypeOfUnit(int type) {
    if (type == 0) {
        return TypeOfUnit::infantryman;
    }
    if (type == 1) {
        return TypeOfUnit::cavalryman;
    }
    if (type == 2) {
        return TypeOfUnit::tank;
    }
    if (type == 3) {
        return TypeOfUnit::armoredCar;
    }
    if (type == 4) {
        return TypeOfUnit::artillery;
    }
    return TypeOfUnit::infantryman;
}

std::string getTypeOfUnit(Unit* unit) {
    Infantryman* infantryman = dynamic_cast<Infantryman*>(unit);
    if (infantryman)
        return "infantryman";
    Cavalryman* cavalryman = dynamic_cast<Cavalryman*>(unit);
    if (cavalryman)
        return "cavalryman";
    Tank* tank = dynamic_cast<Tank*>(unit);
    if (tank)
        return "tank";
    ArmoredCar* armoredCar = dynamic_cast<ArmoredCar*>(unit);
    if (armoredCar)
        return "armoredCar";
    Artillery* artillery = dynamic_cast<Artillery*>(unit);
    if (artillery)
        return "artillery";
    return "none";
}

void Unit::setId(unsigned long long id) {
    _id = id;
}

void Unit::setCost(int cost) {
    _cost = cost;
}

void Unit::setHealth(double health) {
    _health = health;
}

void Unit::setDamage(double damage) {
    _damage = damage;
}

void Unit::setPointsOfMobility(double pointsOfMobility) {
    _pointsOfMobility = pointsOfMobility;
}

void Unit::setPositionOfUnit(Coordinates coordinates) {
    _coordinates = coordinates;
}

void Unit::setPlayerId(int playerId) {
    _playerId = playerId;
}

void Unit::setAttackRange(int attackRange) {
    _attackRange = attackRange;
}

void Unit::setImageOnPlayground(char imageOnPlayground) {
    _imageOnPlaygroud = imageOnPlayground;
}

char Unit::getImageOnPlayGround() {
    return _imageOnPlaygroud;
}

unsigned long long Unit::getId() {
    return _id;
}

int Unit::getCost() {
    return _cost;
}

double Unit::getHealth() {
    return _health;
}

int Unit::getPointsOfMobility() {
    return _pointsOfMobility;
}

int Unit::getPlayerId() {
    return _playerId;
}

int Unit::getAttackRange() {
    return _attackRange;
}

void Infantryman::heal() {
    _health = std::min(_health * 1.1, DefaultInfatrymanStats::health);
}

void Cavalryman::heal() {
    _health = std::min(_health * 1.1, DefaultCavalrymanStats::health);
}

void Tank::heal() {
    _health = std::min(_health * 1.1, DefaultTankStats::health);
}

void ArmoredCar::heal() {
    _health = std::min(_health * 1.1, DefaultArmoredCarStats::health);
}

void Artillery::heal() {
    _health = std::min(_health * 1.1, DefaultArtilleryStats::health);
}

void Infantryman::recoveryOfPointOfMobility() {
    _pointsOfMobility = DefaultInfatrymanStats::pointsOfMobility;
}

void Cavalryman::recoveryOfPointOfMobility() {
    _pointsOfMobility = DefaultCavalrymanStats::pointsOfMobility;
}

void Tank::recoveryOfPointOfMobility() {
    _pointsOfMobility = DefaultTankStats::pointsOfMobility;
}

void ArmoredCar::recoveryOfPointOfMobility() {
    _pointsOfMobility = DefaultArmoredCarStats::pointsOfMobility;
}

void Artillery::recoveryOfPointOfMobility() {
    _pointsOfMobility = DefaultArtilleryStats::pointsOfMobility;
}

Infantryman::Infantryman(): Unit() {}

Cavalryman::Cavalryman(): Unit() {}

Tank::Tank(): Unit() {}

ArmoredCar::ArmoredCar(): Unit() {}

Artillery::Artillery(): Unit() {}
