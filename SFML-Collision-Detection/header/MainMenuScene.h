#pragma once
#include "Scene.h"

#include "Button.h"
#include "Floor.h"

class MainMenuScene : public Scene
{
public:
	explicit MainMenuScene(sf::RenderWindow& window);

	void update(float dt) override;
	void render(sf::RenderWindow& window) override;

private:
	sf::RenderWindow& m_winRef;
	sf::RectangleShape m_bgRect;
	sf::RectangleShape m_fbBanner;
	
	Button m_btnStart;
	Button m_btnScore;
	Floor m_floor;
};

