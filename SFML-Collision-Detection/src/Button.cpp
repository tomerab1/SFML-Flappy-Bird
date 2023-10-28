#include "../header/Button.h"

#include "../header/ResourceLocator.h"

Button::Button(const std::string& textureName, const sf::RectangleShape& rect) :
	m_aabb{ rect },
	m_rect{ rect }
{
	m_rect.setTexture(ResourceLocator<TextureFactory>::getTexture(textureName).get());
}

void Button::setPosition(const sf::Vector2f& pos)
{
	m_rect.setPosition(pos);
	m_aabb.update(m_rect);
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(m_rect);
}

bool Button::isClicked(const sf::RenderWindow& window)
{
	auto [mouseX, mouseY] = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	auto [min, max] = m_aabb.getBounds();
	bool isIntersecting = mouseX >= min.x && mouseX <= max.x &&
		mouseY >= min.y && mouseY <= max.y;

	return isIntersecting && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
