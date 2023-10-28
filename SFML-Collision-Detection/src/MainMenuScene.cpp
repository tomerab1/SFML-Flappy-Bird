#include "../header/MainMenuScene.h"

#include "../header/Globals.h"
#include "../header/ResourceLocator.h"
#include "../header/EventEmitter.h"

#include <iostream>

MainMenuScene::MainMenuScene(sf::RenderWindow& window) : m_winRef{ window },
m_btnStart{ "btnPlay", sf::RectangleShape({40, 20}) },
m_btnScore{ "btnScore", sf::RectangleShape({40, 20}) },
m_floor{ sf::Vector2f(0, SCREEN_HEIGHT - 31),
*ResourceLocator<TextureFactory>::getTexture("floorTexture") }
{
	m_bgRect.setTexture(ResourceLocator<TextureFactory>::getTexture("bgTexture").get());
	m_bgRect.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));

	m_fbBanner.setTexture(ResourceLocator<TextureFactory>::getTexture("labelFlappyBird").get());
	m_fbBanner.setSize({ 120, 40 });
	m_fbBanner.setPosition(sf::Vector2f(30, SCREEN_HEIGHT / 2 - 90));

	m_btnStart.setPosition({ 30.f, SCREEN_HEIGHT - 90 });
	m_btnScore.setPosition({ SCREEN_WIDTH - 70.f, SCREEN_HEIGHT - 90 });
}

void MainMenuScene::update(float dt)
{
	if (m_btnStart.isClicked(m_winRef)) {
		ResourceLocator<AudioFactory>::play("swooshSound", sf::Time::Zero);
		EventEmitter::emit({ GameEventTypes::GAME_START });
	}
}

void MainMenuScene::render(sf::RenderWindow& window)
{
	window.draw(m_bgRect);
	window.draw(m_fbBanner);
	m_floor.render(window);
	m_btnStart.render(window);
	m_btnScore.render(window);
}