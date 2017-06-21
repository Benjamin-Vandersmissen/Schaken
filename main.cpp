#include <iostream>
#include <vector>
#include "Schaakbord.h"
#include "GameWindow.h"
int main() {
    fl_register_images();
    GameWindow* win = new GameWindow(600,600,"Schaken");
    return Fl::run();
}