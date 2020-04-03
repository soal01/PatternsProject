#include"../include/Unit.h"

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

Infantryman::Infantryman(): Unit() {}

Cavalryman::Cavalryman(): Unit() {}

Tank::Tank(): Unit() {}

ArmoredCar::ArmoredCar(): Unit() {}

Artillery::Artillery(): Unit() {}
