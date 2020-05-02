#include"Cell.h"

Cell::Cell(): _coordinates('A', 0), _terrain(nullptr), _unit(nullptr) {}

void Cell::setCoordinates(Coordinates coordinates) {
    _coordinates = coordinates;
}

void Cell::setTerrain(Terrain* terrain) {
    _terrain = terrain;
}

void Cell::setUnit(Unit* unit) {
    _unit = unit;
}

char Cell::getImageOnPlayground() {
    if (_unit) {
        return _unit->getImageOnPlayGround(); 
    }
    else {
        return _terrain->getImageOnPlayGround();
    }
}

Terrain* Cell::getTerrain() {
    return _terrain;
}

Unit* Cell::getUnit() {
    return _unit;
}