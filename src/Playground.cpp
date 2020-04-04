#include"../include/Playground.h"
#include<iostream>

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
    for (unsigned i = 0; i < SIZE_OF_PLAYGROUND; ++i) {
        for (unsigned j = 0; j < SIZE_OF_PLAYGROUND; ++j) {
            std::cout << _cells[i][j]->getImageOnPlayground() << " ";
        }
        std::cout << std::endl;
    }
}

void Playground::setUnitOnPlayground(Coordinates coordinates, TypeOfUnit typeOfUnit) {
    Unit* newUnit = _players[numberOfActivePlayer].buyUnit(builder, typeOfUnit);
    newUnit->setPositionOfUnit(coordinates);
    _cells[coordinates.first][coordinates.second]->setUnit(newUnit);
}