#pragma once
#include"Coordinates.h"
#include"Terrain.h"
#include"Unit.h"

class Cell {
private:
    Coordinates _coordinates;
    Terrain* _terrain;
    Unit* _unit;

public:
    Cell();
    void setCoordinates(Coordinates coordinates);
    void setTerrain(Terrain* terrain);
    void setUnit(Unit* unit);
    char getImageOnPlayground();
};