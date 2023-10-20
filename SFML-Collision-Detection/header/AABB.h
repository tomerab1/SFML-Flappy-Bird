#pragma once

#include <SFML/Graphics.hpp>
#include <utility>

#include "BoundingShape.h"

class AABB : public BoundingShape
{
public:
	explicit AABB(const sf::Vector2f& min, const sf::Vector2f& max);
	explicit AABB(const sf::Sprite& shape);

	void update(const sf::Sprite& shape);
	bool intersect(const BoundingShape& other) const;


	const std::pair<const sf::Vector2f&, const sf::Vector2f&> getBounds() const;

private:
	sf::Vector2f m_min;
	sf::Vector2f m_max;
};

