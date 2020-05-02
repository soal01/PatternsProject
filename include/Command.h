#pragma once
#include"Playground.h"

class Command {
protected:    
    Playground *playground = nullptr;
    Coordinates from, to;
    TypeOfUnit typeOfUnit;
public:
    Command(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
     playground(playground), from(from), to(to), typeOfUnit(typeOfUnit) {}
    virtual void execute() = 0;
};

class MoveCommand: public Command {
    MoveCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
    Command::Command(playground, from, to, typeOfUnit) {}
    void execute() override;
};


class BuyCommand: public Command {
    BuyCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
    Command::Command(playground, from, to, typeOfUnit) {}
    void execute() override;
};

class InfoCommand: public Command {
    InfoCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
    Command::Command(playground, from, to, typeOfUnit) {}
    void execute() override;
};