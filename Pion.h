//
// Created by Benjamin on 19/06/2017.
//

#ifndef SCHAKEN_PION_H
#define SCHAKEN_PION_H

#include <vector>
#include <string>

bool isValid(int x ,int y );

class Pion {
private:
    bool hasMoved;
    int direction;
protected:
    int x;
    int y;
    int color;
public:
    Pion(int x, int y, int color);

    virtual std::vector<std::pair<int, int> > validMoves();

    virtual void move(int x, int y);

    virtual const char * getType();

    int getColor() const;

};


#endif //SCHAKEN_PION_H
