//
// Created by Benjamin on 19/06/2017.
//

#include "Paard.h"

Paard::Paard(int x, int y, int color) : Pion(x, y, color) {

}

std::vector<std::pair<int, int> > Paard::validMoves() {
    std::vector<std::pair<int, int> > moves;
    for(int a = -2; a <= 2; a++){
        for(int b = -2; b <= 2; b++){
            if (std::abs(a) + std::abs(b) == 3 && isValid(x+a, y+b)){
                moves.push_back(std::make_pair(x+a, y+b));
            }
        }
    }
    return moves;
}

const char * Paard::getType() {
    return "Paard";
}
