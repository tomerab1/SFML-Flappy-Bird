#include "../header/Bird.h"

#include "../header/AABB.h"
#include "../header/Floor.h"
#include "../header/Globals.h"
#include "../header/EventEmitter.h"

#include <iostream>

static constexpr float PLAYER_ROTATION_SPEED = 100.f;

Bird::Bird(const sf::Vector2f& pos, const sf::Texture& texture)
{
	m_playerSprite.setPosition(pos);
	m_playerSprite.setTexture(texture);
	m_playerSprite.setTextureRect({ 0,0,16,16 });
	m_aabb = std::make_unique<AABB>(m_playerSprite);
}

void Bird::render(sf::RenderWindow& window)
{
	window.draw(m_playerSprite);
}

void Bird::update(float dt)
{
	if (m_hitFloor) return;

	onCeilingCollision();

	m_acceleration += {0, WORLD_GRAVITY};

	if (m_isAlive && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (!m_leftMouseButtonPressed) {
			m_acceleration = { 0, -8.f };
			m_velocity = { 0, 0 };
			m_leftMouseButtonPressed = true;
		}
	}
	else {
		m_leftMouseButtonPressed = false;
	}

	if (m_isAlive) {
		updateAnimation(dt);
		updateRotation(dt);
	}

	m_velocity += m_acceleration;
	auto pos = m_playerSprite.getPosition() + m_velocity * dt;
	pos.y = std::max(pos.y, 0.f);

	m_playerSprite.setPosition(pos);
	m_aabb->update(m_playerSprite);
}

void Bird::update(float dt, GameEntity& entity)
{
	if (m_hitFloor) return;

	if (m_aabb->intersect(entity.getBoudingShape())) {
		if (dynamic_cast<Floor*>(&entity)) {
			m_hitFloor = true;
			m_acceleration = { 0,0 };
			m_velocity = { 0, 0 };
		}
		
		m_isAlive = false;
		EventEmitter::emit({ GameEventTypes::GAME_OVER });
	}
}

BoundingShape& Bird::getBoudingShape()
{
	return *m_aabb;
}

void Bird::setTextureRect(const sf::IntRect& textureRect)
{
	m_playerSprite.setTextureRect(textureRect);
	m_aabb->update(m_playerSprite);
}

void Bird::updateRotation(float dt)
{
	if (m_acceleration.y <= 0) {
		m_playerRotation -= PLAYER_ROTATION_SPEED * dt;
	}
	else {
		m_playerRotation += PLAYER_ROTATION_SPEED * dt;
	}

	m_playerRotation = std::clamp(m_playerRotation, -25.f, 25.f);
	m_playerSprite.setRotation(m_playerRotation);
}

void Bird::onCeilingCollision()
{
	auto [min, max] = m_aabb->getBounds();

	if (min.y < 0) {
		m_isAlive = false;
		EventEmitter::emit({ GameEventTypes::GAME_OVER });
	}
}

void Bird::updateAnimation(float dt)
{
	m_animationDuration -= dt;
	if (m_animationDuration <= 0) {
		auto [left, top, width, height] = m_playerSprite.getTextureRect();
		setTextureRect({ width * m_animationFrame, top, width, height });
		m_animationFrame = (m_animationFrame + 1) % BIRD_NUM_OF_ANIMATIONS;
		m_animationDuration = BIRD_ANIMATION_DURATION;
	}
}
