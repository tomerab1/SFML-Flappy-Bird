#pragma once

#include "Globals.h"
#include "GameEntity.h"
#include "BoundingShape.h"

#include <array>

static constexpr int BIRD_NUM_OF_ANIMATIONS = 4;
static constexpr float BIRD_ANIMATION_DURATION = 0.2f;

class Bird : public GameEntity
{
public:
	explicit Bird(const sf::Vector2f& pos, const sf::Texture& texture);

	void render(sf::RenderWindow& window) override;
	void update(float dt) override;
	void update(float dt, GameEntity& entity) override;
	BoundingShape& getBoudingShape() override;
	void setTextureRect(const sf::IntRect& textureRect) override;

private:
	void updateAnimation(float dt);
	void updateRotation(float dt);
	void onCeilingCollision();

private:
	float m_animationDuration{ BIRD_ANIMATION_DURATION };
	float m_playerRotation{ 0 };
	int m_animationFrame{ 0 };

	bool m_hitFloor{ false };
	bool m_isAlive{ true };
	bool m_playedHit{ false };
	bool m_leftMouseButtonPressed{ false };

	sf::Vector2f m_velocity{ 0, 200.f };
	sf::Vector2f m_acceleration;

	sf::Sprite m_playerSprite;
	std::unique_ptr<BoundingShape> m_aabb;
};

