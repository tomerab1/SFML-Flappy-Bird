#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "../header/AABB.h"

class Application {
public:
	Application(const sf::VideoMode& vMode, const std::string& path);

	int exec();

private:
	sf::RenderWindow m_window;
};