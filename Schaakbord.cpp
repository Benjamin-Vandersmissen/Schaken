//
// Created by Benjamin on 19/06/2017.
//

#include "Schaakbord.h"
int sign(int a){
    return (a > 0 ? 1 : (a < 0 ? -1 : 0));
}


Schaakbord::Schaakbord() {
    /**
     * Colors : 0 = BLACK
     *          1 = WHITE
     */

    for(int a = 0; a < 8; a++){
        std::vector<Pion*> row;
        for(int b = 0; b < 8; b++){
            row.push_back(NULL);
        }
        board.push_back(row);
    }

    for(int i = 0; i <=1; i++){
        for(int a = 0; a < 8; a++){
            board[a][1+5*i] = new Pion(a, 1 + 5*i, i);
        }
    }
    for(int i = 0; i <=1; i++){
        for(int a = 0; a <= 1; a ++){
            board[7*a][7*i] = new Toren(7*a, 7*i, i);
            board[1+5*a][7*i] = new Paard(1+5*a, 7*i, i);
            board[2+3*a][7*i] = new Loper(2+3*a, 7*i, i);
        }
        board[3][7*i] = new Koningin(3,7*i,i);
        board[4][7*i] = new Koning(4,7*i,i);
    }
}

bool Schaakbord::move(int x1, int y1, int x2, int y2) {
    if (!validMove(x1,y1,x2,y2))
        return false;
    Pion* pion = board[x1][y1];
    color = !pion->getColor();
    delete board[x2][y2];
    board[x2][y2] = pion;
    board[x1][y1] = NULL;
    pion->move(x2,y2);
    return true;
}

bool Schaakbord::lineOfSight(int x1, int y1, int x2, int y2) {
    if (y1 == y2){

        for(int a = x1+sign(x2-x1); a != x2; a += sign(x2-x1)){
            if (board[a][y1] != NULL)
                return false;
        }
        return true;
    }
    else if (x1 == x2){
        for(int b = y1+sign(y2-y1); b != y2; b += sign(y2-y1)){
            if (board[x1][b] != NULL)
                return false;
        }
        return true;
    }
    else{
        for(int i = 1; x1+i*(sign(x2-x1)) != x2 && y1 + i*(sign(y2-y1)) != y2; i++){
            if(board[x1+i*sign(x2-x1)][y1+i*sign(y2-y1)] != NULL)
                return false;
        }
        return true;
    }
}

std::ostream &operator<<(std::ostream &stream, Schaakbord &bord) {
    for(int b = 0; b  < 8; b++){
        for(int a = 0; a < 8; a++){
            if (bord.board[a][b] != NULL)
                stream << bord.board[a][b]->getType() << ' ';
            else
                stream << "////" << ' ';
        }
        stream << std::endl;
    }
    return stream;
}

Pion *Schaakbord::operator()(int x, int y) {
    return board[x][y];
}

bool Schaakbord::validMove(int x1, int y1, int x2, int y2) {
    if (board[x1][y1] == NULL)
        return false;
    Pion* pion = board[x1][y1];
    if (pion->getColor() != color)
        return false;

    std::pair<int, int> coords = std::make_pair(x2,y2);
    std::vector<std::pair<int, int> > mogelijkeMoves = pion->validMoves();
    if (std::find(mogelijkeMoves.begin(), mogelijkeMoves.end(), coords) == mogelijkeMoves.end()) //Invalid move
        return false;

    if (board[x2][y2] != NULL){
        if (pion->getColor() == board[x2][y2]->getColor())
            return false;
    }

    if (pion->getType() == "Pion"){
        if (x1 != x2){ //schuin -> stuk pakken
            if (board[x2][y2] == NULL)
                return false;
        }
        else{
            if (!lineOfSight(x1,y1,x2,y2) || board[x2][y2] != NULL)
                return false;
        }
    }
    if (pion->getType() != "Paard"){
        if (!lineOfSight(x1,y1,x2,y2))
            return false;
    }

    return true;
}
