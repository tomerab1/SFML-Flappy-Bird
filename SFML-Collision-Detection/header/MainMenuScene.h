#pragma once
#include "Scene.h"
class MainMenuScene : public Scene
{
public:
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;

private:
};

