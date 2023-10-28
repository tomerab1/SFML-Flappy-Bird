#pragma once
#include "Scene.h"

#include "Button.h"
#include "Floor.h"

class GameOverScene : public Scene
{
public:
	explicit GameOverScene(sf::RenderWindow& window);

	void update(float dt) override;
	void render(sf::RenderWindow& window) override;

private:
	sf::RenderWindow& m_winRef;
	sf::RectangleShape m_bgRect;
	sf::RectangleShape m_gameOverBanner;

	Button m_btnMenu;
	Floor m_floor;
};

