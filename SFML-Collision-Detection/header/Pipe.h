#pragma once
#include "GameEntity.h"

class Pipe : public GameEntity
{
public:
	Pipe(const sf::Vector2f& pos, const sf::Texture& texture, bool isFlipped = false);
	Pipe(const Pipe& other);

	Pipe& operator=(const Pipe& other);

	void render(sf::RenderWindow& window) override;
	void update(float dt) override;
	void update(float dt, GameEntity& entity) override;
	void setTextureRect(const sf::IntRect& textureRect) override;
	BoundingShape& getBoudingShape() override;

private:
	sf::Vector2f m_velocity{ -30, 0 };
	sf::Sprite m_pipeSprite;
	std::unique_ptr<BoundingShape> m_aabb;
};

