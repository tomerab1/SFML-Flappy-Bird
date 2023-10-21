#include "../header/GameScene.h"

#include "../header/ResourceLocator.h"
#include "../header/Globals.h"

GameScene::GameScene() :
	m_bird{ sf::Vector2f(SCREEN_WIDTH / 2 - BIRD_WIDTH, SCREEN_HEIGHT / 2 - BIRD_WIDTH),
	*ResourceLocator<TextureFactory>::getTexture("birdTexture") },
	m_floor{ sf::Vector2f(0, SCREEN_HEIGHT - 31),
	*ResourceLocator<TextureFactory>::getTexture("floorTexture") }
{
	m_bg.setTexture(ResourceLocator<TextureFactory>::getTexture("bgTexture").get());
	m_bg.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
}

void GameScene::update(float dt)
{
	m_bird.update(dt);
	m_bird.update(dt, m_floor);
}

void GameScene::render(sf::RenderWindow& window)
{
	window.draw(m_bg);
	m_bird.render(window);
	m_floor.render(window);
}
