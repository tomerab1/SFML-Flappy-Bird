#include "../header/Floor.h"
#include "../header/Globals.h"

Floor::Floor(const sf::Vector2f& pos, const sf::Texture& texture)
{
	m_floorSprite.setPosition(pos);
	m_floorSprite.setTexture(texture);
	m_floorSprite.setScale({ 2.5f, 1.f });
	m_floorSprite.setTextureRect({ 0, 0, 180, 32 });

	m_aabb = std::make_unique<AABB>(m_floorSprite);
}

void Floor::render(sf::RenderWindow& window)
{
	window.draw(m_floorSprite);
}

void Floor::update(float dt)
{
}

void Floor::update(float dt, GameEntity& entity)
{

}

BoundingShape& Floor::getBoudingShape()
{
	return *m_aabb;
}

void Floor::setTextureRect(const sf::IntRect& textureRect)
{
	m_floorSprite.setTextureRect(textureRect);
}