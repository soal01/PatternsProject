#include"main.h"
#include<iostream>


int main() {
    Playground* playground = Playground::getInstance();
    playground->printMap();
    std::cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1"<<std::endl;
    playground->setUnitOnPlayground(Coordinates(1, 3), TypeOfUnit::artillery);
    playground->setUnitOnPlayground(Coordinates(2, 3), TypeOfUnit::armoredCar);
    playground->setUnitOnPlayground(Coordinates(3, 3), TypeOfUnit::tank);
    playground->setUnitOnPlayground(Coordinates(4, 3), TypeOfUnit::infantryman);
    playground->setUnitOnPlayground(Coordinates(5, 3), TypeOfUnit::cavalryman);
    playground->printMap();
    return 0;
}