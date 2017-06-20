#include <iostream>
#include <vector>
#include "Schaakbord.h"
#include "GameWindow.h"
int main() {
    GameWindow* win = new GameWindow(600,600,"Schaken");
    return Fl::run();
}