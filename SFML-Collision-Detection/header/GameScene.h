#pragma once
#include "Scene.h"

#include "Bird.h"
#include "Floor.h"

#include <SFML/Graphics.hpp>

class GameScene : public Scene
{
public:
	GameScene();
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;

private:
	Bird m_bird;
	Floor m_floor;
	sf::RectangleShape m_bg;
};

