#include<cstdlib>
#include<ctime>
#include"../include/CellBuilder.h"


void CellBuilder::reset() {
    result = new Cell();
}

void CellBuilder::setTerrain(Terrain* terrain = nullptr) {
    result->setTerrain(terrain);
}

Cell* CellBuilder::getResult() {
    return result;
}
