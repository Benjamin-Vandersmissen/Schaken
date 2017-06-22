//
// Created by benji on 20.06.17.
//

#ifndef SCHAKEN_GAMEWINDOW_H
#define SCHAKEN_GAMEWINDOW_H
#include "FL/Fl_Double_Window.H"
#include "Schaakbord.h"
#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Shared_Image.H"
#include "FL/Fl_PNG_Image.H"
#include <algorithm>



class Schaakstuk : Fl_Box{
private:
    Fl_PNG_Image* img;
    int a;
    int b;
    int _Xoff = 0;
    int _Yoff = 0;
public:
    Schaakstuk(int a, int b, int w, int h, Pion *pion);

    void draw();

    int handle(int event);
};

class GameWindow : Fl_Double_Window{
private:
    Schaakbord* schaakbord;
    std::vector<std::vector<Schaakstuk*> > _bord;
public:
    friend class Schaakstuk;

    GameWindow(int W, int H, const char *l);

    Fl_Group* Bord = NULL;

};

#endif //SCHAKEN_GAMEWINDOW_H
