//
// Created by benji on 20.06.17.
//

#include "GameWindow.h"

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
    fl_register_images();
    new Schaakstuk(0,0,(*schaakbord)(7,7));
    this->show();
}

Schaakstuk::Schaakstuk(int a, int b, Pion *pion) : Fl_Box(200*a, 200*b, 200, 200, pion->getType()){
    std::vector<Fl_PNG_Image* > textures = {TEXTURE_ZWART_KONING, TEXTURE_ZWART_KONINGIN, TEXTURE_ZWART_LOPER,
                                            TEXTURE_ZWART_PAARD, TEXTURE_ZWART_PION, TEXTURE_ZWART_TOREN,
                                            TEXTURE_WIT_KONING, TEXTURE_WIT_KONINGIN, TEXTURE_WIT_LOPER,
                                            TEXTURE_WIT_PAARD, TEXTURE_WIT_PION, TEXTURE_WIT_TOREN};
    std::vector<std::string > types = {"Koning", "Koningin", "Loper", "Paard", "Pion", "Toren"};
    int i;
    if (std::find(types.begin(), types.end(), (std::string)pion->getType()) != types.end()){
        i = std::distance(types.begin(), std::find(types.begin(), types.end(), (std::string) pion->getType()));
    }
    this->image(textures[i+pion->getColor()*types.size()]);
}
