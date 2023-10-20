#include "../header/Bird.h"
#include "../header/AABB.h"
#include "../header/Globals.h"

#include <iostream>

static constexpr float PLAYER_ROTATION_SPEED = 100.f;


Bird::Bird(const sf::Vector2f& pos, const sf::Texture& texture)
{
	m_playerSprite.setPosition(pos);
	m_playerSprite.setTexture(texture);
	m_playerSprite.setScale({ 2.f, 2.f });
	m_playerSprite.setTextureRect({ 0,0,16,16 });

	m_aabb = std::make_unique<AABB>(m_playerSprite);
}

void Bird::render(sf::RenderWindow& window)
{
	window.draw(m_playerSprite);
}

void Bird::update(float dt)
{
	CollisionType collisionType = isCollidingWorldBoundaries();
	m_acceleration += {0, WORLD_GRAVITY};

	if (!m_isAlive || collisionType != CollisionType::NONE) {
		auto pos = m_playerSprite.getPosition();

		if (m_isAlive) {
			m_velocity = { 0,0 };
			switch (collisionType) {
			case CollisionType::UP:
				pos += { 0, static_cast<float>(m_playerSprite.getTextureRect().height * 2) };
				break;
			default:
				break;
			}
		}

		m_velocity += m_acceleration;
		pos += m_velocity * dt;
		pos = { pos.x, std::min(pos.y, static_cast<float>(SCREEN_HEIGHT - m_playerSprite.getTextureRect().height * 2)) };

		m_playerSprite.setPosition(pos);
		m_playerSprite.setRotation(90);
		m_aabb->update(m_playerSprite);
		m_isAlive = false;
	}
	else {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (!m_leftMouseButtonPressed) {
				m_acceleration = { 0, -11.f };
				m_velocity = { 0, 0 };
				m_leftMouseButtonPressed = true;
			}
		}
		else {
			m_leftMouseButtonPressed = false;
		}

		m_velocity += m_acceleration;
		auto pos = m_playerSprite.getPosition() + m_velocity * dt;

		updateAnimation(dt);
		updateRotation(dt);

		m_playerSprite.setPosition(pos);
		m_aabb->update(m_playerSprite);
	}
}

void Bird::update(float dt, GameEntity& entity)
{
}

void Bird::setTextureRect(const sf::IntRect& textureRect)
{
	m_playerSprite.setTextureRect(textureRect);
	m_aabb->update(m_playerSprite);
}

sf::Sprite& Bird::getEntity()
{
	return m_playerSprite;
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

CollisionType Bird::isCollidingWorldBoundaries()
{
	auto [min, max] = m_aabb->getBounds();

	if (min.y < 0) return CollisionType::UP;
	if (max.y > SCREEN_HEIGHT) return CollisionType::BOTTOM;
	return CollisionType::NONE;
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
