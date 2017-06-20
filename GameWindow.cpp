//
// Created by benji on 20.06.17.
//

#include "GameWindow.h"

GameWindow::GameWindow(int W, int H, const char *l) : Fl_Double_Window(W, H, l) {
    schaakbord = new Schaakbord;
    this->Bord = new Fl_Group(0,0,this->w(), this->h());
    {
        for(int b = 0; b < 8; b++){
            for(int a = 0; a < 8; a++){
                Fl_Button* box = new Fl_Button(75*a, 75*b, 75,  75);
                box->down_box(FL_BORDER_FRAME);
                box->box(FL_BORDER_BOX);
                if ((a+b)%2){
                    box->color(fl_rgb_color(51,34,6));
                }else{
                    box->color(FL_LIGHT2);
                }
                box->callback(selectedCB, this);
            }
        }
    }
    this->Bord->end();
    this->SyncBoard();
    this->show();
}

void GameWindow::SyncBoard() {
    for(int a = 0; a < 8; a++){
        for(int b = 0; b < 8; b++){
            Pion* pion = (*schaakbord)(a,b);
            if (pion != NULL){
                this->Bord->child(a+8*b)->label(pion->getType());
                this->Bord->child(a+8*b)->labelcolor((pion->getColor() ? FL_WHITE : FL_BLACK));
            }
        }
    }
    this->Bord->redraw();
}

Pion *GameWindow::findPion(Fl_Button *b) {
    for(int i = 0; i < this->Bord->children(); i++){
        if (this->Bord->child(i) == b)
            return (*schaakbord)(i%8, i/8);
    }
}

void selectedCB(Fl_Widget *w, void *v) {
    Fl_Button* button = (Fl_Button*) w;
    w->color2(FL_GREEN);
    GameWindow* win = (GameWindow*) v;
    for(int i = 0; i < win->Bord->children(); i++){
        Fl_Button* b = (Fl_Button*) win->Bord->child(i);
        b->value(0);
    }
    if (win->findPion(button)){
        button->value(1);
    }
}
