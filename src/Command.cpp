#include"../include/Command.h"

#include<iostream>

void MoveCommand::execute() {
    if (playground->isCorrectMove(from, to))
        playground->moveUnit(from, to);
    else
        playground->setError("uncorrect move");
}


void BuyCommand::execute() {
    playground->setUnitOnPlayground(from, typeOfUnit);
}

void InfoCommand::execute() {
    playground->setInfo(playground->getInfoAboutCell(from));
}

Command::Command(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
     playground(playground), from(from), to(to), typeOfUnit(typeOfUnit) {}


MoveCommand::MoveCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
    Command(playground, from, to, typeOfUnit) {}

BuyCommand::BuyCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
    Command(playground, from, to, typeOfUnit) {}

InfoCommand::InfoCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
    Command(playground, from, to, typeOfUnit) {}



Command* CommandReader::readCommand(Playground* mainPlayground) {
    std::cout << "Command: ";
    std::string typeOfCommand;
    Coordinates from = Coordinates(-1, -1);
    Coordinates to = Coordinates(-1, -1);
    TypeOfUnit typeOfUnit = convertToTypeOfUnit(0);
    std::cin >> typeOfCommand;
    if (typeOfCommand == "move") {
        try {
            int first, second;
            std::cin >> first >> second;
            from = Coordinates(first, second);
            std::cin >> first >> second;
            to = Coordinates(first, second);
            return new MoveCommand(mainPlayground, from, to, typeOfUnit);
        }catch (...) {
            mainPlayground->setError("invalid arguments");
            std::cout << std::endl;
            return nullptr;
        }
    }
    if (typeOfCommand == "info") {
        try {
            int first, second;
            std::cin >> first >> second;
            from = Coordinates(first, second);
            return new InfoCommand(mainPlayground, from, to, typeOfUnit);
        }catch (...) {
            mainPlayground->setError("invalid arguments");
            std::cout << std::endl;
            return nullptr;
        }
    }
    if (typeOfCommand == "buy") {
        try {
            int first, second;
            std::cin >> first >> second;
            from = Coordinates(first, second);
            std::cin >> first;
            typeOfUnit = convertToTypeOfUnit(first);
            return new BuyCommand(mainPlayground, from, to, typeOfUnit);
        }catch (...) {
            mainPlayground->setError("invalid arguments");
            std::cout << std::endl;
            return nullptr;
        }
    }
    mainPlayground->setError("invalid command");
    std::cout << std::endl;
    return nullptr;
}