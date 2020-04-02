#pragma once
#include"Cell.h"

class Playground {
private:
    static const unsigned SIZE_OF_PLAYGROUND = 20;
    static Cell cells[SIZE_OF_PLAYGROUND][SIZE_OF_PLAYGROUND];
    static Playground* playground;
public:
};