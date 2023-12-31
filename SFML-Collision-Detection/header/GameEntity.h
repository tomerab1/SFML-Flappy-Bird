#pragma once

#include "BoundingShape.h"

#include <SFML/Graphics.hpp>
#include <memory>

class GameEntity {
public:
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void update(float dt) = 0;
	virtual void update(float dt, GameEntity& entity) = 0;
	virtual void setTextureRect(const sf::IntRect& textureRect) = 0;
	virtual BoundingShape& getBoudingShape() = 0;
	virtual ~GameEntity() {}
};