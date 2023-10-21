#pragma once
#include "GameEntity.h"

#include "AABB.h"

#include <SFML/Graphics.hpp>

class Floor : public GameEntity
{
public:
	explicit Floor(const sf::Vector2f& pos, const sf::Texture& texture);

	void render(sf::RenderWindow& window) override;
	void update(float dt) override;
	void update(float dt, GameEntity& entity) override;
	BoundingShape& getBoudingShape() override;
	void setTextureRect(const sf::IntRect& textureRect) override;

private:
	sf::Sprite m_floorSprite;
	std::unique_ptr<BoundingShape> m_aabb;
};

