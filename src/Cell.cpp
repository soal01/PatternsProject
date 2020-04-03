#include"../include/Cell.h"


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