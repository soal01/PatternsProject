#pragma once
#include"Terrain.h"


class TerrainBuilder {
private:
public:
    virtual void reset() = 0;
    virtual void setAttackBonus() = 0;
    virtual void setDefenseBonus() = 0;
    virtual void setMoveBonus() = 0;
    virtual void setImageOnPlayground() = 0;
    virtual Terrain* getResult() = 0;
};

class ForestBuilder : public TerrainBuilder {
private:
    Forest *result;
public:
    void reset() override;
    void setAttackBonus() override;
    void setDefenseBonus() override;
    void setMoveBonus() override;
    void setImageOnPlayground() override;
    Forest* getResult() override;
};

class MountainBuilder : public TerrainBuilder {
private:
    Mountain *result;
public:
    void reset() override;
    void setAttackBonus() override;
    void setDefenseBonus() override;
    void setMoveBonus() override;
    void setImageOnPlayground() override;
    Mountain* getResult() override;
};

class GrassLandBuilder : public TerrainBuilder {
private:
    GrassLand *result;
public:
    void reset() override;
    void setAttackBonus() override;
    void setDefenseBonus() override;
    void setMoveBonus() override;
    void setImageOnPlayground() override;
    GrassLand* getResult() override;
};