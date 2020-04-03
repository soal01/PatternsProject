#include"include/TerrainBuilder.h"


void ForestBuilder::reset() {
    result = new Forest();
}

void ForestBuilder::setAttackBonus() {
    result->setAttackBonus(0);
}

void ForestBuilder::setDefenseBonus() {
    result->setDefenseBonus(1);
}

void ForestBuilder::setMoveBonus() {
    result->setMoveBonus(-0.5);
}

void ForestBuilder::setImageOnPlayground() {
    result->setImageOnPlayground('?');
}

Forest* ForestBuilder::getResult() {
    return result;
}


void MountainBuilder::reset() {
    result = new Mountain();
}

void MountainBuilder::setAttackBonus() {
    result->setAttackBonus(1);
}

void MountainBuilder::setDefenseBonus() {
    result->setDefenseBonus(2);
}

void MountainBuilder::setMoveBonus() {
    result->setMoveBonus(-1);
}

void MountainBuilder::setImageOnPlayground() {
    result->setImageOnPlayground('^');
}

Mountain* MountainBuilder::getResult() {
    return result;
}


void GrassLandBuilder::reset() {
    result = new GrassLand();
}

void GrassLandBuilder::setAttackBonus() {
    result->setAttackBonus(1);
}

void GrassLandBuilder::setDefenseBonus() {
    result->setDefenseBonus(-1);
}

void GrassLandBuilder::setMoveBonus() {
    result->setMoveBonus(1);
}

void GrassLandBuilder::setImageOnPlayground() {
    result->setImageOnPlayground('_');
}

GrassLand* GrassLandBuilder::getResult() {
    return result;
}