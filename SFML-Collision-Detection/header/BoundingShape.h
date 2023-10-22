#pragma once

#include <SFML/Graphics.hpp>

class BoundingShape {
public:
	virtual void update(const sf::Sprite& shape) = 0;
	virtual bool intersect(const BoundingShape& other) const = 0;
	virtual const std::pair<sf::Vector2f, sf::Vector2f> getBounds() const = 0;
};