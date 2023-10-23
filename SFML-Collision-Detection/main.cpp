#include <iostream>

#include "header/Globals.h"
#include "header/Application.h"

int main()
{
    Application app(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT), "Flappy Bird");
    return app.exec();
}
