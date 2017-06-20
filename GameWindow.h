//
// Created by benji on 20.06.17.
//

#ifndef SCHAKEN_GAMEWINDOW_H
#define SCHAKEN_GAMEWINDOW_H
#include "FL/Fl_Double_Window.H"
#include "Schaakbord.h"
#include "FL/Fl.H"
#include "FL/Fl_Button.H"

class GameWindow : Fl_Double_Window{
private:
    Schaakbord* schaakbord;
public:
    GameWindow(int W, int H, const char *l);

    Fl_Group* Bord = NULL;

    void SyncBoard();

    Pion* findPion(Fl_Button* b);
};

void selectedCB(Fl_Widget* w, void* v);

#endif //SCHAKEN_GAMEWINDOW_H
