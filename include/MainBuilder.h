#pragma once
#include"Terrain.h"
#include"Cell.h"
#include"Unit.h"
#include"TerrainBuilder.h"
#include"CellBuilder.h"
#include"UnitBuilder.h"

class MainBuilder {
private:
    unsigned nextUnitId;

public:
    CellBuilder cellBuilder;
    ForestBuilder forestBuilder;
    MountainBuilder mountainBuilder;
    GrassLandBuilder grassLandBuilder;
    Terrain* buildTerrain(TerrainBuilder* builder);
    Cell* buildCell(CellBuilder* builder, Terrain* terrainOfCell = nullptr);
    Unit* buildUnit(UnitBuilder* builder);
};