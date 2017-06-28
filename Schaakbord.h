//
// Created by Benjamin on 19/06/2017.
//

#ifndef SCHAKEN_SCHAAKBORD_H
#define SCHAKEN_SCHAAKBORD_H

#include "Pion.h"
#include "Koningin.h"
#include "Koning.h"
#include "Paard.h"
#include "Loper.h"
#include "Toren.h"
#include <iostream>
#include <algorithm>

class Schaakbord {
private:
    std::vector<std::vector<Pion*> > board;
    int color = 1;
public:
    friend std::ostream& operator<<(std::ostream& stream, Schaakbord& bord);

    Schaakbord();

    bool move(int x1, int y1, int x2, int y2);

    bool lineOfSight(int x1, int y1, int x2, int y2);

    Pion* operator()(int x, int y);

    bool validMove(int x1, int y1, int x2, int y2);
};

std::ostream& operator<<(std::ostream& stream, Schaakbord& bord);

#endif //SCHAKEN_SCHAAKBORD_H
