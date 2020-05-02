#include"../include/Playground.h"
#include<iostream>
#include<iomanip>

Playground* Playground::mainPlayground = nullptr;

void Playground::initializePlayers() {
    numberOfActivePlayer = 0;
    for (unsigned i = 0; i < COUNT_OF_PLAYERS; ++i) {
        _players[i] = Player(i);
    }
}


void Playground::initializeCells() {
    srand(time(0));
    Terrain* terrain = nullptr;
    for (unsigned i = 0; i < SIZE_OF_PLAYGROUND; ++i) {
        for (unsigned j = 0; j < SIZE_OF_PLAYGROUND; ++j) {
            int generatedTypeOfTerrain = rand() % 3;
            terrain = nullptr;
            if (generatedTypeOfTerrain == TypeOfTerrain::forest) {
                terrain = builder.buildTerrain(new ForestBuilder());
            }
            if (generatedTypeOfTerrain == TypeOfTerrain::mountain) {
                terrain = builder.buildTerrain(new MountainBuilder());
            }
            if (generatedTypeOfTerrain == TypeOfTerrain::grassLand) {
                terrain = builder.buildTerrain(new GrassLandBuilder());
            }
            _cells[i][j] = builder.buildCell(new CellBuilder(), terrain);
        }
    }
}

Playground::Playground() {
    initializePlayers();
    initializeCells();
}

void Playground::deletePlayers() {
    for (unsigned i = 0; i < COUNT_OF_PLAYERS; ++i) {
        _players[i].~Player();
    }
}

void Playground::deleteCells() {
    for (unsigned i = 0; i < SIZE_OF_PLAYGROUND; ++i) {
        for (unsigned j = 0; j < SIZE_OF_PLAYGROUND; ++j) {
            delete _cells[i][j];
        }
    }
}

Playground::~Playground() {
    deletePlayers();
    deleteCells();
}

Playground* Playground::getInstance() {
    if (!mainPlayground)
        mainPlayground = new Playground();
    return mainPlayground;
}

void Playground::deleteInstance() {
    if (mainPlayground) {
        delete mainPlayground;
    }
    mainPlayground = nullptr;
}



void Playground::printMap() {
    std::cout << std::string('=', 25);
    std:: cout << "  ";
    for (unsigned i = 0; i < SIZE_OF_PLAYGROUND; ++i) {
        std::cout << (char)('A' + i) << " ";
    }
    std::cout << std::endl;

    for (unsigned i = 0; i < SIZE_OF_PLAYGROUND; ++i) {
        std::cout << std::right << std::setw(2)<< i << " ";
        for (unsigned j = 0; j < SIZE_OF_PLAYGROUND; ++j) {
            std::cout << _cells[i][j]->getImageOnPlayground() << " ";
        }
        std::cout << std::endl;
    }
}

void Playground::print() {
    printMap();
    std::cout << "Info:\n" << _info;
    std::cout << "Error: " << _error;
}

void Playground::setUnitOnPlayground(Coordinates coordinates, TypeOfUnit typeOfUnit) {
    Unit* newUnit = _players[numberOfActivePlayer].buyUnit(builder, typeOfUnit);
    newUnit->setPositionOfUnit(coordinates);
    _cells[coordinates.first][coordinates.second]->setUnit(newUnit);
}

void Playground::setInfo(std::string newInfo) {
    _info = newInfo;
}

void Playground::setError(std::string newError) {
    _error = newError;
}

Command* Playground::readCommand() {
    std::cout << "Command: ";
    std::string typeOfCommand;
    Coordinates from = Coordinates(-1, -1);
    Coordinates to = Coordinates(-1, -1);
    TypeOfUnit typeOfUnit = 0;
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
            setError("invalid arguments");
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
            setError("invalid arguments");
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
            typeOfUnit = first;
            return new BuyCommand(mainPlayground, from, to, typeOfUnit);
        }catch (...) {
            setError("invalid arguments");
            std::cout << std::endl;
            return nullptr;
        }
    }
    setError("invalid command");
    std::cout << std::endl;
    return nullptr;
}