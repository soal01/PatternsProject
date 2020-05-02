#include"../include/Command.h"

void MoveCommand::execute() {
    playground->moveUnit(from, to);
}


void BuyCommand::execute() {
    playground->setUnitOnPlayground(from, typeOfUnit);
}

void InfoCommand::execute() {
    playground->setInfo(playground->getInfoAboutCell(from));
}

MoveCommand::MoveCommand() {
    
}