//
// Created by Benjamin on 19/06/2017.
//

#include "Koning.h"

Koning::Koning(int x, int y, int color) : Pion(x, y, color) {

}

std::vector<std::pair<int, int> > Koning::validMoves() {
    std::vector<std::pair<int, int> > moves;
    for(int a = -1; a <= 1; a++){
        for(int b = -1; b <= 1; b++){
            if(b == 0 && a == 0)
                continue;
            if (isValid(x+a,y+b))
                moves.push_back(std::make_pair(x+a, y+b));
        }
    }
    return moves;
}

const char * Koning::getType() {
    return "Koning";
}
