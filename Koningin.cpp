//
// Created by Benjamin on 19/06/2017.
//

#include "Koningin.h"

Koningin::Koningin(int x, int y, int color) : Pion(x, y, color) {}

std::vector<std::pair<int, int> > Koningin::validMoves() {
    std::vector<std::pair<int, int> > moves;
    for(int a = -1; a <= 1; a++){
        for(int b = -1; b <= 1; b++){
            if(b == 0 && a == 0)
                continue;
            for(int i = 1; i < 8; i++) {
                if (isValid(x + i*a, y + i*b))
                    moves.push_back(std::make_pair(x + i*a, y + i*b));
                else
                    break;
            }
        }
    }
    return moves;
}

const char * Koningin::getType() {
    return "Koningin";
}
