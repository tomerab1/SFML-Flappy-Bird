#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <stack>

#include "Scene.h"
#include "AABB.h"

class Application {
public:
	Application(const sf::VideoMode& vMode, const std::string& title);

	int exec();

private:
	void handleFrameworkEvents();
	void handleGameEvents();
	void loadAssets() const;

private:
	sf::RenderWindow m_window;
	std::stack<std::unique_ptr<Scene>> m_scenes;
};