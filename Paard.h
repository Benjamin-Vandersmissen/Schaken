//
// Created by Benjamin on 19/06/2017.
//

#ifndef SCHAKEN_PAARD_H
#define SCHAKEN_PAARD_H
#include "Pion.h"

class Paard : public Pion{
public:
    Paard(int x, int y, int color);

    std::vector<std::pair<int, int> > validMoves();

    const char * getType();
};


#endif //SCHAKEN_PAARD_H
