#include"../include/Terrain.h"

std::string getTypeOfTerrain(Terrain* terrain) {
    Forest* forest = dynamic_cast<Forest*>(terrain);
    if (forest)
        return "forest";
    Mountain* mountain = dynamic_cast<Mountain*>(terrain);
    if (mountain)
        return "mountain";
    GrassLand* grassLand = dynamic_cast<GrassLand*>(terrain);
    if (grassLand)
        return "grass land";
}


void Terrain::setAttackBonus(double attackBonus) {
    _attackBonus = attackBonus;
}

void Terrain::setDefenseBonus(double defenseBonus) {
    _defenseBonus = defenseBonus;
}

void Terrain::setMoveBonus(double moveBonus) {
    _moveBonus = moveBonus;
}

void Terrain::setImageOnPlayground(char imageOnPlayground) {
    _imageOnPlaygroud = imageOnPlayground;
}

char Terrain::getImageOnPlayGround() {
    return _imageOnPlaygroud;
}

double Terrain::getMoveBonus() {
    return _moveBonus;
}

Forest::Forest(): Terrain() {}

Mountain::Mountain(): Terrain() {}

GrassLand::GrassLand(): Terrain() {}