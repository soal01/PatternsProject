#include"Player.h"
#include<iostream>

Player::Player(int id): id(id), money(START_MONEY), hisTurn(false) {}

Player::~Player() {
    for (auto x: units) {
        delete x.second;
    }
}