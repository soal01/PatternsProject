#pragma once
#include"Playground.h"
#include"../include/Unit.h"

class Command {
protected:    
    Playground* playground;
    Coordinates from, to;
    TypeOfUnit typeOfUnit; 
public:
    Command(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit);
    virtual void execute() = 0;
};

class MoveCommand: public Command {
public:
    MoveCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit);
    void execute() override;
};


class BuyCommand: public Command {
public:
    BuyCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit);
    void execute() override;
};

class InfoCommand: public Command {
public:
    InfoCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit);
    void execute() override;
};


class CommandReader {
public:
    static Command* readCommand(Playground* mainPlayground);
};



class CommandChecker {
public:
    static bool checkMoveCommand(Playground* mainPlayground, Coordinates from, Coordinates to);
    static bool checkBuyCommand(Playground* mainPlayground, Coordinates from, TypeOfUnit typeOfUnit);
    static bool checkInfoCommand(Playground* mainPlayground, Coordinates from);
    static bool isAttackMove(Playground* mainPlayground, Coordinates from, Coordinates to);
};