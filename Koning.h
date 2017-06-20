//
// Created by Benjamin on 19/06/2017.
//

#ifndef SCHAKEN_KONING_H
#define SCHAKEN_KONING_H

#include "Pion.h"

class Koning : public Pion{
public:
    Koning(int x, int y, int color);

    std::vector<std::pair<int, int> > validMoves();

    const char * getType();
};


#endif //SCHAKEN_KONING_H
