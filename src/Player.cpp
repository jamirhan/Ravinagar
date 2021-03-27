#include "Player.h"


Player::Player(int x, int y): cords(Point(x, y)) {};


void Player::update_coins(int new_coins) {
    points += new_coins;
}
