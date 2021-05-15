#include "Player.h"


Player::Player(int x, int y) : coord(Point(x, y)) {};


void Player::UpdateCoins(int new_coins) {
    points += new_coins;
}

int Player::GetPoints() const {
    return points;
}

const Point& Player::GetCoord() const {
    return coord;
}

bool Player::IsMoved() const {
    return moved;
}

void Player::Move() {
    Player::moved = true;
}

void Player::Move(Point new_coord) {
    coord = new_coord;
}

