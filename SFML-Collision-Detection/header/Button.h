#pragma once

#include <SFML/Graphics.hpp>

#include "AABB.h"

class Button
{
public:
	explicit Button(const std::string& textureName, const sf::RectangleShape& rect);

	void setPosition(const sf::Vector2f& pos);
	void render(sf::RenderWindow& window);
	void setTexture(const sf::Texture& texture);
	bool isClicked(const sf::RenderWindow& window);

private:
	AABB m_aabb;
	sf::RectangleShape m_rect;
	bool m_leftMouseButtonPressed{ false };
};

