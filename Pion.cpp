//
// Created by Benjamin on 19/06/2017.
//

#include "Pion.h"

Pion::Pion(int x, int y, int color) : x(x), y(y), hasMoved(false), color(color) {
    if (y <= 4)
        direction = 1;
    else
        direction = -1;
}

std::vector<std::pair<int, int> > Pion::validMoves() {
    if (!isValid(x,y+direction))
        return {};
    std::vector<std::pair<int, int> > moves = {std::make_pair(x,y+direction)};
    if (!hasMoved && isValid(x, y+2*direction))
        moves.push_back(std::make_pair(x,y+2*direction));
    if (isValid(x+1,y+direction))
        moves.push_back(std::make_pair(x+1,y+direction));
    if (isValid(x-1,y+direction))
        moves.push_back(std::make_pair(x-1,y+direction));
    return moves;
}

void Pion::move(int x, int y) {
    this->x = x;
    this->y = y;
    hasMoved = true;
}

const char * Pion::getType() {
    return "Pion";
}

int Pion::getColor() const {
    return color;
}

bool isValid(int x, int y) {
    return (x >= 0 && x <=7 && y >=0 && y <= 7);
}
