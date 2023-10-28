#include "../header/GameOverScene.h"

#include "../header/ResourceLocator.h"
#include "../header/EventEmitter.h"
#include "../header/Globals.h"

GameOverScene::GameOverScene(sf::RenderWindow& window) : m_winRef{ window },
m_floor{ sf::Vector2f(0, SCREEN_HEIGHT - 31),
*ResourceLocator<TextureFactory>::getTexture("floorTexture") },
m_btnMenu{ "btnMenu", sf::RectangleShape({40, 20}) }
{
	m_bgRect.setTexture(ResourceLocator<TextureFactory>::getTexture("bgTexture").get());
	m_bgRect.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));

	m_gameOverBanner.setTexture(ResourceLocator<TextureFactory>::getTexture("labelGameOver").get());
	m_gameOverBanner.setSize({ 120, 40 });
	m_gameOverBanner.setPosition(sf::Vector2f(30, SCREEN_HEIGHT / 2 - 90));

	m_btnMenu.setPosition({ SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT / 2 - 30 });
}

void GameOverScene::update(float dt)
{
	if (m_btnMenu.isClicked(m_winRef)) {
		EventEmitter::emit({ GameEventTypes::GAME_MENU });
		ResourceLocator<AudioFactory>::play("swooshSound", sf::Time::Zero);
	}
}

void GameOverScene::render(sf::RenderWindow& window)
{
	window.draw(m_bgRect);
	window.draw(m_gameOverBanner);
	m_btnMenu.render(window);
	m_floor.render(window);
}
