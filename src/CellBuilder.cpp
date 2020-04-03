#include<cstdlib>
#include<ctime>
#include"../include/CellBuilder.h"


void CellBuilder::reset() {
    //delete result;
    result = new Cell();
}

void CellBuilder::setTerrain(Terrain* terrain) {
    result->setTerrain(terrain);
}

Cell* CellBuilder::getResult() {
    return result;
}

CellBuilder::~CellBuilder() {
    delete result;
}
