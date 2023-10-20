#include <iostream>

#include "header/Globals.h"
#include "header/Application.h"

int main()
{
    Application app(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Collision Detection");
    return app.exec();
}
