#pragma once
#include"Cell.h"

class CellBuilder {
private:
    Cell* result;
public:
    void reset();
    void setTerrain(Terrain* terrain = nullptr);
    Cell* getResult();
    ~CellBuilder();
};