#include <iostream>

#include "header/Globals.h"
#include "header/Application.h"

int main()
{
    Application app(sf::VideoMode(2 * SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT), "Collision Detection");
    return app.exec();
}
