#pragma once
#include "Scene.h"

#include "Globals.h"
#include "Bird.h"
#include "PipeContainer.h"
#include "Floor.h"

#include <SFML/Graphics.hpp>
#include <vector>

class GameScene : public Scene
{
public:
	GameScene();
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;

private:
	Bird m_bird;
	Floor m_floor;
	PipeContainer m_pipes;

	int m_score{ 0 };
	bool m_didInc{ false };
	bool m_isGameOver{ false };

	sf::Text m_text;
	sf::RectangleShape m_bg;
};

