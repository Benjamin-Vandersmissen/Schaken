//
// Created by Benjamin on 19/06/2017.
//

#ifndef SCHAKEN_LOPER_H
#define SCHAKEN_LOPER_H
#include "Pion.h"

class Loper : public Pion{
public:
    Loper(int x, int y, int color);

    std::vector<std::pair<int, int> > validMoves();

    const char * getType();
};


#endif //SCHAKEN_LOPER_H
