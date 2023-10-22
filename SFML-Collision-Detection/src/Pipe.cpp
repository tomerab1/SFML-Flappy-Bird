#include "../header/Pipe.h"

#include "../header/ResourceLocator.h"
#include "../header/AABB.h"
#include "../header/Bird.h"
#include "../header/EventEmitter.h"

#include <iostream>

Pipe::Pipe(const sf::Vector2f& pos, const sf::Texture& texture, bool isFlipped)
{
	m_pipeSprite.setTexture(texture);
	m_pipeSprite.setPosition(pos);
	m_pipeSprite.setScale(0.5, isFlipped ? -0.5 : 0.5);
	m_pipeSprite.setTextureRect(sf::IntRect(0, 0, 32, 320));
	m_aabb = std::make_unique<AABB>(m_pipeSprite);
}

Pipe::Pipe(const Pipe& other) : m_pipeSprite{ other.m_pipeSprite }
{
	m_aabb = std::make_unique<AABB>(*other.m_aabb);
}

Pipe& Pipe::operator=(const Pipe& other)
{
	if (this == &other) return *this;

	m_aabb = std::make_unique<AABB>(*other.m_aabb);
	return *this;
}

void Pipe::render(sf::RenderWindow& window)
{
	window.draw(m_pipeSprite);
}

void Pipe::update(float dt)
{
	m_pipeSprite.move(m_velocity * dt);
	m_aabb->update(m_pipeSprite);
}

void Pipe::update(float dt, GameEntity& entity)
{
}

void Pipe::setTextureRect(const sf::IntRect& textureRect)
{
	m_pipeSprite.setTextureRect(textureRect);
}

BoundingShape& Pipe::getBoudingShape()
{
	return *m_aabb;
}
