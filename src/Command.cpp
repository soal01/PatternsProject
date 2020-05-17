#include"../include/Command.h"

#include<iostream>
#include<queue>

void MoveCommand::execute() {
    std::pair<bool, double> checkMove = CommandChecker::checkMoveCommand(playground, from, to);
    if (checkMove.first) {
        if (CommandChecker::isAttackMove(playground, from, to))
            playground->calculateAttack(from, to);
        else
            playground->moveUnit(from, to, checkMove.second);
    }
    else
        playground->setError("uncorrect move");
}


void BuyCommand::execute() {
    if (CommandChecker::checkBuyCommand(playground, from, typeOfUnit))
        playground->setUnitOnPlayground(from, typeOfUnit);
    else
        playground->setError("You haven't got enough money or uncorrect place");  
}

void InfoCommand::execute() {
    if (CommandChecker::checkInfoCommand(playground, from))
        playground->setInfo(playground->getInfoAboutCell(from));
    else
        playground->setError("Uncorrect place");
}

void NextTurnCommand::execute() {
    playground->nextTurn();
}

Command::Command(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
     playground(playground), from(from), to(to), typeOfUnit(typeOfUnit) {}


MoveCommand::MoveCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
    Command(playground, from, to, typeOfUnit) {}

BuyCommand::BuyCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
    Command(playground, from, to, typeOfUnit) {}

InfoCommand::InfoCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
    Command(playground, from, to, typeOfUnit) {}

NextTurnCommand::NextTurnCommand(Playground* playground, Coordinates from, Coordinates to, TypeOfUnit typeOfUnit):
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
    if (typeOfCommand == "next turn") {
        mainPlayground->nextTurn();
    }
    mainPlayground->setError("invalid command");
    std::cout << std::endl;
    return nullptr;
}

bool isCorrectCoordinates(Coordinates coordinates) {
    if (coordinates.first >= 20 || coordinates.first < 0 || coordinates.second >= 20 || coordinates.second < 0)
        return false;
    else
        return true;
}

bool CommandChecker::checkBuyCommand(Playground* mainPlayground, Coordinates from, TypeOfUnit typeOfUnit) {
    if (!isCorrectCoordinates(from))
        return false;
    if (mainPlayground->getCell(from)->getUnit())
        return false;
    if (mainPlayground->numberOfActivePlayer == 1 && from.first > 5)
        return false;
    if (mainPlayground->numberOfActivePlayer == 0 && from.first < 15)
        return false;
    int currentMoney = mainPlayground->getCurrentPlayer().getMoney();
    int necessaryMoney;
    if (typeOfUnit == TypeOfUnit::infantryman)
        necessaryMoney = DefaultInfatrymanStats::cost;
    if (typeOfUnit == TypeOfUnit::cavalryman)
        necessaryMoney = DefaultCavalrymanStats::cost;
    if (typeOfUnit == TypeOfUnit::tank)
        necessaryMoney = DefaultTankStats::cost;
    if (typeOfUnit == TypeOfUnit::armoredCar)
        necessaryMoney = DefaultArmoredCarStats::cost;
    if (typeOfUnit == TypeOfUnit::artillery)
        necessaryMoney = DefaultArtilleryStats::cost;
    return necessaryMoney <= currentMoney;
}

bool CommandChecker::checkInfoCommand(Playground* mainPlayground, Coordinates from) {
    return isCorrectCoordinates(from);
}

void calculateTable(Playground* mainPlayground, Coordinates from, double** table) {
    table[from.first, from.second] = 0;
    std::queue<std::pair<Coordinates, double>> potentialUpdates;
    potentialUpdates.push({from, fabs(mainPlayground->getCell(from)->getTerrain()->getMoveBonus() / 2)});
    while (!potentialUpdates.empty()) {
        std::pair<Coordinates, double> newUpdate = potentialUpdates.front();
        Coordinates currentCell = newUpdate.first;
        potentialUpdates.pop();
        if (!isCorrectCoordinates(currentCell))
            continue;
        double nowBonus = fabs(mainPlayground->getCell(currentCell)->getTerrain()->getMoveBonus() / 2);
        if (nowBonus + newUpdate.second < table[currentCell.first][currentCell.second]) {
            table[currentCell.first][currentCell.second] = newUpdate.second + nowBonus;
            potentialUpdates.push({Coordinates(currentCell.first + 1, currentCell.second + 1), nowBonus});
            potentialUpdates.push({Coordinates(currentCell.first + 1, currentCell.second), nowBonus});
            potentialUpdates.push({Coordinates(currentCell.first, currentCell.second + 1), nowBonus});
            potentialUpdates.push({Coordinates(currentCell.first - 1, currentCell.second + 1), nowBonus});
            potentialUpdates.push({Coordinates(currentCell.first + 1, currentCell.second - 1), nowBonus});
            potentialUpdates.push({Coordinates(currentCell.first - 1, currentCell.second), nowBonus});
            potentialUpdates.push({Coordinates(currentCell.first, currentCell.second - 1), nowBonus});
            potentialUpdates.push({Coordinates(currentCell.first - 1, currentCell.second - 1), nowBonus});
        }
    }
}

int distBetweenCoordinates(Coordinates a, Coordinates b) {
    return std::max(abs(a.first - b.first), abs(a.second - b.second));
}

std::pair<bool, double> CommandChecker::checkMoveCommand(Playground* mainPlayground, Coordinates from, Coordinates to) {
    if (!isCorrectCoordinates(from) || !isCorrectCoordinates(to))
        return {false, 0};
    if (!mainPlayground->getCell(from)->getUnit())
        return {false, 0};
    if (mainPlayground->getCell(to)->getUnit() && mainPlayground->getCell(to)->getUnit()->getPlayerId() == mainPlayground->numberOfActivePlayer)
        return {false, 0};
    double rangeOfAttack = mainPlayground->getCell(from)->getUnit()->getAttackRange();
    if (rangeOfAttack < distBetweenCoordinates(from, to))
        return {false, 0};
    if (mainPlayground->getCell(from)->getUnit()->getPlayerId() != mainPlayground->numberOfActivePlayer)
        return {false, 0};
    double** tableOfPointsOfMobility = new double*[20];
    for (unsigned i = 0; i < 20; ++i) {
        tableOfPointsOfMobility[i] = new double[20];
        for (unsigned j = 0; j < 20; ++j) {
            tableOfPointsOfMobility[i][j] = 1e9;
        }
    }
    calculateTable(mainPlayground, from, tableOfPointsOfMobility);
    double currentPointsOfMobility = mainPlayground->getCell(from)->getUnit()->getPointsOfMobility();
    double neededPointsOfMobility = tableOfPointsOfMobility[to.first][to.second];
    for (unsigned i = 0; i < 20; ++i)
        delete tableOfPointsOfMobility[i];
    delete[] tableOfPointsOfMobility;
    return {currentPointsOfMobility >= neededPointsOfMobility, neededPointsOfMobility};
}

bool CommandChecker::isAttackMove(Playground* mainPlayground, Coordinates from, Coordinates to) {
    return mainPlayground->getCell(to)->getUnit() != nullptr;
}