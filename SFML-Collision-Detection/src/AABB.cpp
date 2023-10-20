#include "../header/AABB.h"

#include <iostream>

AABB::AABB(const sf::Vector2f& min, const sf::Vector2f& max) : m_min{min}, m_max{max}
{
}

AABB::AABB(const sf::Sprite& sprite)
{
	auto [posX, posY] = sprite.getGlobalBounds().getPosition();
	auto [sizeX, sizeY] = sprite.getGlobalBounds().getSize();

	m_min = { posX, posY };
	m_max = { posX + sizeX, posY + sizeY };
}

void AABB::update(const sf::Sprite& sprite)
{
	auto [posX, posY] = sprite.getGlobalBounds().getPosition();
	auto [sizeX, sizeY] = sprite.getGlobalBounds().getSize();

	m_min = { posX, posY };
	m_max = { posX + sizeX, posY + sizeY };
}

bool AABB::intersect(const BoundingShape& other) const
{
	auto [min, max] = other.getBounds();

	if (m_max.x < min.x || m_min.x > max.x) return false;
	if (m_max.y < min.y || m_min.y > max.y) return false;

	return true;
}

const std::pair<const sf::Vector2f&, const sf::Vector2f&> AABB::getBounds() const
{
	return std::make_pair(m_min, m_max);
}

