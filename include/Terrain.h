#pragma once

class Terrain {
private:

protected:
    double attackBonus;
    double defenseBonus;
    double moveBonus;
    char imageOnPlayGroud;

public:
};


class Forest : public Terrain {
private:

public:
    Forest();
};


class Mountains : public Terrain {
private:

public:
    Mountains();
};


class GrassLand {
private:

public:
    GrassLand();
};