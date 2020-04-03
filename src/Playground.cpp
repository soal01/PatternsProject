#include"../include/Playground.h"
#include<iostream>

void Playground::printMap() {
    for (unsigned i = 0; i < SIZE_OF_PLAYGROUND; ++i) {
        for (unsigned j = 0; j < SIZE_OF_PLAYGROUND; ++j) {
            std::cout << cells[i][j].getImageOnPlayground() << " ";
        }
        std::cout << std::endl;
    }
}