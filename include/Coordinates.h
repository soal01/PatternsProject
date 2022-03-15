#pragma once
#include<cmath>
#include<algorithm>

struct Coordinates {
    int first;
    int second;
    Coordinates(): first(0), second(0) {}
    Coordinates(int first, int second): first(first), second(second) {}
    Coordinates(int first, char second): first(first), second(second - 'A') {}
};


