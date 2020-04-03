#include"include/Terrain.h"

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