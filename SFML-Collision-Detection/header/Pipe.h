#pragma once
#include "GameEntity.h"

class Pipe : public GameEntity
{
public:
	Pipe(const sf::Vector2f& pos, const sf::Texture& texture);

	void render(sf::RenderWindow& window) override;
	void update(float dt) override;
	void update(float dt, GameEntity& entity) override;
	void setTextureRect(const sf::IntRect& textureRect) override;
	BoundingShape& getBoudingShape() override;

private:
	sf::Sprite m_pipeSprite;
	std::unique_ptr<BoundingShape> m_aabb;
};

