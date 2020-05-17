#include"../include/Playground.h"
#include<iostream>
#include<iomanip>

Playground* Playground::mainPlayground = nullptr;

void Playground::initializePlayers() {
    numberOfActivePlayer = 0;
    for (unsigned i = 0; i < COUNT_OF_PLAYERS; ++i) {
        _players[i] = Player(i);
    }
}


void Playground::initializeCells() {
    srand(time(0));
    Terrain* terrain = nullptr;
    for (unsigned i = 0; i < SIZE_OF_PLAYGROUND; ++i) {
        for (unsigned j = 0; j < SIZE_OF_PLAYGROUND; ++j) {
            int generatedTypeOfTerrain = rand() % 3;
            terrain = nullptr;
            if (generatedTypeOfTerrain == TypeOfTerrain::forest) {
                terrain = builder.buildTerrain(new ForestBuilder());
            }
            if (generatedTypeOfTerrain == TypeOfTerrain::mountain) {
                terrain = builder.buildTerrain(new MountainBuilder());
            }
            if (generatedTypeOfTerrain == TypeOfTerrain::grassLand) {
                terrain = builder.buildTerrain(new GrassLandBuilder());
            }
            _cells[i][j] = builder.buildCell(new CellBuilder(), terrain);
        }
    }
}

Playground::Playground() {
    initializePlayers();
    initializeCells();
}

void Playground::deletePlayers() {
    for (unsigned i = 0; i < COUNT_OF_PLAYERS; ++i) {
        _players[i].~Player();
    }
}

void Playground::deleteCells() {
    for (unsigned i = 0; i < SIZE_OF_PLAYGROUND; ++i) {
        for (unsigned j = 0; j < SIZE_OF_PLAYGROUND; ++j) {
            delete _cells[i][j];
        }
    }
}

Playground::~Playground() {
    deletePlayers();
    deleteCells();
}

Playground* Playground::getInstance() {
    if (!mainPlayground)
        mainPlayground = new Playground();
    return mainPlayground;
}

void Playground::deleteInstance() {
    if (mainPlayground) {
        delete mainPlayground;
    }
    mainPlayground = nullptr;
}



void Playground::printMap() {
    std::cout << std::string('=', 25);
    std:: cout << "  ";
    for (unsigned i = 0; i < SIZE_OF_PLAYGROUND; ++i) {
        std::cout << (char)('A' + i) << " ";
    }
    std::cout << std::endl;

    for (unsigned i = 0; i < SIZE_OF_PLAYGROUND; ++i) {
        std::cout << std::right << std::setw(2)<< i << " ";
        for (unsigned j = 0; j < SIZE_OF_PLAYGROUND; ++j) {
            std::cout << _cells[i][j]->getImageOnPlayground() << " ";
        }
        std::cout << std::endl;
    }
}

void Playground::print() {
    printMap();
    std::cout << "Info:\n" << _info;
    std::cout << "Error: " << _error;
}

void Playground::setUnitOnPlayground(Coordinates coordinates, TypeOfUnit typeOfUnit) {
    Unit* newUnit = _players[numberOfActivePlayer].buyUnit(builder, typeOfUnit);
    newUnit->setPositionOfUnit(coordinates);
    _cells[coordinates.first][coordinates.second]->setUnit(newUnit);
}

void Playground::setInfo(std::string newInfo) {
    _info = newInfo;
}

void Playground::setError(std::string newError) {
    _error = newError;
}

bool Playground::isEndOfGame() {
    for (unsigned i = 0; i < COUNT_OF_PLAYERS; ++i) {
        if (_players[i].countOfUnits() == 0)
            return true;
    }
    return false;
}

std::string Playground::getInfoAboutCell(Coordinates coordinates) {
    size_t x = coordinates.first;
    size_t y = coordinates.second;
    std::string ans = "Info:\n";
    ans += "Coordinates: " + std::to_string((char)('A' + x)) + std::to_string(y) + "\n";
    ans += "Terrain: " + getTypeOfTerrain(_cells[x][y]->getTerrain()) + "\n";
    Unit* unit = _cells[x][y]->getUnit();
    ans += "Unit: " + getTypeOfUnit(unit);
    if (unit) {
        ans += "player's ID: " + std::to_string(unit->getPlayerId()) + "\n";
        ans += "health: " + std::to_string(unit->getHealth()) + "\n";
        ans += "points of mobility: " + std::to_string(unit->getPointsOfMobility()) + "\n";
    }
    return ans;
}

void Playground::calculateAttack(Coordinates from, Coordinates to) {
    size_t xFrom = from.first;
    size_t yFrom = from.second;
    size_t xTo = to.first;
    size_t yTo = to.second;
    Unit* attacker = _cells[xFrom][yFrom]->getUnit();
    Unit* defender = _cells[xTo][yTo]->getUnit();
    int idOfAttacker = attacker->getId();
    int idOfDefender = defender->getId();
    Terrain* terrainOfAttacker = _cells[xFrom][yFrom]->getTerrain();
    Terrain* terrainOfDefender = _cells[xTo][yTo]->getTerrain();
    double attackerDamage = attacker->getDamage() * (terrainOfAttacker->getAttackBonus() - 0.5 * terrainOfDefender->getDefenseBonus());
    double defenderDamage = defender->getDamage() * terrainOfDefender->getAttackBonus() * 0.5;
    _players[attacker->getPlayerId()].damageUnit(idOfAttacker, defenderDamage);
    _players[defender->getPlayerId()].damageUnit(idOfDefender, attackerDamage);
    if (attacker->getHealth() - defenderDamage < 0) {
        _players[attacker->getPlayerId()].destroyUnit(idOfAttacker);
        _cells[xFrom][yFrom]->setUnit(nullptr);
    }
    if (defender->getHealth() - attackerDamage < 0) {
        _players[defender->getPlayerId()].destroyUnit(idOfDefender);
        _cells[xTo][yTo]->setUnit(nullptr);
    }
}

void Playground::moveUnit(Coordinates from, Coordinates to, double dist) {
    Unit* moveUnit = _cells[from.first][from.second]->getUnit();
    _cells[to.first][to.second]->setUnit(moveUnit);
    getCurrentPlayer().decreaseMovePointsOfUnit(moveUnit->getId(), dist);
    _cells[from.first][to.second]->setUnit(nullptr);
}

Player Playground::getCurrentPlayer() {
    return _players[numberOfActivePlayer];
}

Cell* Playground::getCell(Coordinates coordinates) {
    return _cells[coordinates.first][coordinates.second];
}

void Playground::nextTurn() {
    numberOfActivePlayer = (numberOfActivePlayer + 1) % COUNT_OF_PLAYERS;
    _players[numberOfActivePlayer].nextTurn();
}