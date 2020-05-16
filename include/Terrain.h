#pragma once
#include<string>

enum TypeOfTerrain {forest, mountain, grassLand};


class Terrain {
private:

protected:
    double _attackBonus;
    double _defenseBonus;
    double _moveBonus;
    char _imageOnPlaygroud;

public:
    virtual void setAttackBonus(double attackBonus);
    virtual void setDefenseBonus(double defenseBonus);
    virtual void setMoveBonus(double moveBonus);
    virtual void setImageOnPlayground(char imageOnPlayground);
    virtual char getImageOnPlayGround();
    virtual double getMoveBonus();
};


class Forest : public Terrain {
private:

public:
    Forest();
};


class Mountain : public Terrain {
private:

public:
    Mountain();
};


class GrassLand : public Terrain {
private:

public:
    GrassLand();
};


class TerrainFeatures {
protected:
    double attackBonus;
    double defenseBonus;
    double moveBonus;
};

class ForestFeatures : public TerrainFeatures {
    ForestFeatures() {
        attackBonus = 0;
        defenseBonus = 1;
        moveBonus = -1.5;
    }
};

class MountainFeatures : public TerrainFeatures {
    MountainFeatures() {
        attackBonus = 1;
        defenseBonus = 1;
        moveBonus = -3;
    }
};

class GrassLandFeatures : public TerrainFeatures {
    GrassLandFeatures() {
        attackBonus = 1;
        defenseBonus = 0;
        moveBonus = -1;
    }
};

std::string getTypeOfTerrain(Terrain* terrain);
