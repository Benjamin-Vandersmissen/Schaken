//
// Created by Benjamin on 19/06/2017.
//

#ifndef SCHAKEN_KONINGIN_H
#define SCHAKEN_KONINGIN_H
#include "Pion.h"

class Koningin : public Pion{
public:
    Koningin(int x, int y, int color);

    std::vector<std::pair<int, int> > validMoves();

    const char * getType();
};


#endif //SCHAKEN_KONINGIN_H
