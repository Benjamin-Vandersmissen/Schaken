//
// Created by benji on 20.06.17.
//

#include "GameWindow.h"

Fl_PNG_Image* resizeImage(Fl_PNG_Image* img, int maxW, int maxH){
    if (img->w() < maxW && img->h() < maxH){
        return img;
    }
    else if (img->h() > img->w()){
        img->RGB_scaling(FL_RGB_SCALING_BILINEAR);
        Fl_PNG_Image* newIMG = (Fl_PNG_Image*)img->copy((double)img->w()/img->h()*maxH, maxH);
        return newIMG;
    }
    else{
        img->RGB_scaling(FL_RGB_SCALING_BILINEAR);
        Fl_PNG_Image* newIMG = (Fl_PNG_Image*)img->copy(maxW ,(double)img->h()/img->w()*maxW);
        return newIMG;
    }
}

Fl_PNG_Image* TEXTURE_WIT_PAARD = new Fl_PNG_Image("./Paard_Wit.png");
Fl_PNG_Image* TEXTURE_WIT_PION = new Fl_PNG_Image("./Pion_Wit.png");
Fl_PNG_Image* TEXTURE_WIT_KONING = new Fl_PNG_Image("./Koning_Wit.png");
Fl_PNG_Image* TEXTURE_WIT_KONINGIN = new Fl_PNG_Image("./Koningin_Wit.png");
Fl_PNG_Image* TEXTURE_WIT_TOREN = new Fl_PNG_Image("./Toren_Wit.png");
Fl_PNG_Image* TEXTURE_WIT_LOPER = new Fl_PNG_Image("./Loper_Wit.png");

Fl_PNG_Image* TEXTURE_ZWART_PAARD = new Fl_PNG_Image("./Paard_Zwart.png");
Fl_PNG_Image* TEXTURE_ZWART_PION = new Fl_PNG_Image("./Pion_Zwart.png");
Fl_PNG_Image* TEXTURE_ZWART_KONING = new Fl_PNG_Image("./Koning_Zwart.png");
Fl_PNG_Image* TEXTURE_ZWART_KONINGIN = new Fl_PNG_Image("./Koningin_Zwart.png");
Fl_PNG_Image* TEXTURE_ZWART_TOREN = new Fl_PNG_Image("./Toren_Zwart.png");
Fl_PNG_Image* TEXTURE_ZWART_LOPER = new Fl_PNG_Image("./Loper_Zwart.png");


GameWindow::GameWindow(int W, int H, const char *l) : Fl_Double_Window(W, H, l) {
    schaakbord = new Schaakbord;
    Bord = new Fl_Group(0,0,W,H);
    {
        for(int a = 0; a < 8; a++){
            for(int b = 0; b < 8; b++){
                Fl_Box* box = new Fl_Box(75*a,75*b, 75,75);
                box->box(FL_BORDER_FRAME);
                box->color(FL_LIGHT2);
                box->color2(FL_GREEN);
            }
        }
    }
    Bord->end();
    for(int a = 0; a < 8; a++){
        for(int b =0; b < 8; b++){
            if ((*schaakbord)(a,b) != NULL)
                new Schaakstuk(a , b, 75, 75, (*schaakbord)(a,b));
        }
    }
    this->show();
}



Schaakstuk::Schaakstuk(int a, int b, int w, int h, Pion *pion) : Fl_Box(w * a, h * b, w, h, pion->getType()), a(a), b(b){
    std::vector<Fl_PNG_Image* > textures = {TEXTURE_ZWART_KONING, TEXTURE_ZWART_KONINGIN, TEXTURE_ZWART_LOPER,
                                            TEXTURE_ZWART_PAARD, TEXTURE_ZWART_PION, TEXTURE_ZWART_TOREN,
                                            TEXTURE_WIT_KONING, TEXTURE_WIT_KONINGIN, TEXTURE_WIT_LOPER,
                                            TEXTURE_WIT_PAARD, TEXTURE_WIT_PION, TEXTURE_WIT_TOREN};
    std::vector<std::string > types = {"Koning", "Koningin", "Loper", "Paard", "Pion", "Toren"};
    int i;
    if (std::find(types.begin(), types.end(), (std::string)pion->getType()) != types.end()){
        i = std::distance(types.begin(), std::find(types.begin(), types.end(), (std::string) pion->getType()));
    }
    this->color(FL_LIGHT2);

    img = resizeImage(textures[i+pion->getColor()*types.size()],w,h);
}

void Schaakstuk::draw() {
    if (img->w() < w())
        img->draw(x() - _Xoff + (w()-img->w())/2, y() - _Yoff);
    else
        img->draw(x() - _Xoff, y() - _Yoff);
}

int Schaakstuk::handle(int event) {
    switch(event){
        case FL_PUSH:
            _Xoff = Fl::event_x() - x();
            _Yoff = Fl::event_y() - y();
            return 1;
        case FL_DRAG:
            this->take_focus();
            position(Fl::event_x(),Fl::event_y());
            this->parent()->redraw();
            return 1;
        case FL_RELEASE:
            _Xoff = 0;
            _Yoff = 0;
//            std::cerr << Fl::event_x()/75 << ' ' << Fl::event_y()/75 << std::endl;
            Schaakbord* bord = ((GameWindow*) this->parent())->schaakbord;
            int newA = Fl::event_x()/w();
            int newB = Fl::event_y()/h();
            if (bord->validMove(a,b,newA,newB)){
                position(w()*newA, h() * newB);
                bord->move(a,b,newA,newB);
                a = newA;
                b = newB;
                std::cerr << *bord << std::endl;
            }
            else{
                position(w()*a, h()*b);
            }
            this->parent()->redraw();
            return 1;
    }
    return 0;
}
