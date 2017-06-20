//
// Created by Benjamin on 19/06/2017.
//

#ifndef SCHAKEN_TOREN_H
#define SCHAKEN_TOREN_H
#include "Pion.h"

class Toren : public Pion{
public:
    Toren(int x, int y, int color);

    std::vector<std::pair<int, int> > validMoves();

    const char * getType();
};


#endif //SCHAKEN_TOREN_H
