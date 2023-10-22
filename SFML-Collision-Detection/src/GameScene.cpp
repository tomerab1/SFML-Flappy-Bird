#include "../header/GameScene.h"

#include "../header/ResourceLocator.h"
#include "../header/EventEmitter.h"
#include "../header/Globals.h"

#include <iostream>

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
	auto [pMin, pMax] = (m_pipes.begin())->getBoudingShape().getBounds();
	auto [bMin, bMax] = m_bird.getBoudingShape().getBounds();

	m_bird.update(dt);
	m_bird.update(dt, m_floor);

	for (auto& pipe : m_pipes) {
		m_bird.update(dt, pipe);
	}

	if (EventEmitter::peek().eventType == GameEventTypes::GAME_OVER) {
		m_isGameOver = true;
	}

	if (!m_isGameOver) {
		m_pipes.update(dt);
	}

	if (!m_isGameOver && std::abs(pMin.x - bMin.x) <= (0.3)) {
		m_score++;
		std::cout << m_score << '\n';
	}
}

void GameScene::render(sf::RenderWindow& window)
{
	window.draw(m_bg);
	m_pipes.render(window);
	m_floor.render(window);
	m_bird.render(window);
}
