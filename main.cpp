#include"main.h"
#include<iostream>


int main() {
    Playground* playground = Playground::getInstance();
    playground->printMap();
    return 0;
}