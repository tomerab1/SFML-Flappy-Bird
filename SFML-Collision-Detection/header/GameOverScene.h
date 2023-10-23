#pragma once
#include "Scene.h"
class GameOverScene : public Scene
{
public:
	void update(float dt) override;
	void render(sf::RenderWindow& window) override;

private:
};

