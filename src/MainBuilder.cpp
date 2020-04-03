#include"../include/MainBuilder.h"

Terrain* MainBuilder::buildTerrain(TerrainBuilder* builder) {
    builder->reset();
    builder->setAttackBonus();
    builder->setDefenseBonus();
    builder->setMoveBonus();
    builder->setImageOnPlayground();
    return builder->getResult();
}

Cell* MainBuilder::buildCell(CellBuilder* builder, Terrain* terrainOfCell = nullptr) {
    builder->reset();
    builder->setTerrain(terrainOfCell);
    return builder->getResult();
}

Unit* MainBuilder::buildUnit(UnitBuilder* builder) {
    builder->reset(nextUnitId++);
    builder->setCost();
    builder->setHealth();
    builder->setDamage();
    builder->setPointsOfMobility();
    builder->setAttackRange();
    builder->setImageOnPlayGround();
    return builder->getResult();
}