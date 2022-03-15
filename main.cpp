#include"main.h"
#include<iostream>


int main() {
    Playground* playground = Playground::getInstance();
    playground->setUpPlayground();
    playground->print();
    while(!playground->isEndOfGame()) {
        Command* command = CommandReader::readCommand(playground->getInstance());
        if (command) 
            command->execute();
        playground->print();
    }
    playground->printWinner();
    return 0;
}