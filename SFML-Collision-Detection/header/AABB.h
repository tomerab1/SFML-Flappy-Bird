#pragma once

#include <SFML/Graphics.hpp>
#include <utility>

#include "BoundingShape.h"

class AABB : public BoundingShape
{
public:
	explicit AABB(const sf::Sprite& shape);
	explicit AABB(const sf::Shape& shape);
	explicit AABB(const BoundingShape& shape);

	void update(const sf::Shape& shape);
	void update(const sf::Sprite& shape);
	bool intersect(const BoundingShape& other) const;

	const std::pair<sf::Vector2f, sf::Vector2f> getBounds() const;

private:
	sf::Vector2f m_min;
	sf::Vector2f m_max;
};

