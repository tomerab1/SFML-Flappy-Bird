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

	m_text.setFont(ResourceLocator<FontFactory>::getFont(R"(.\Res\Flappy Bird Assets\font\font.ttf)"));
	m_text.setCharacterSize(20);
	m_text.setString(std::to_string(m_score));
	m_text.setPosition({ SCREEN_WIDTH / 2, static_cast<float>(m_text.getCharacterSize()) });
}

void GameScene::update(float dt)
{
	auto [pMin, pMax] = m_pipes.begin()->getBoudingShape().getBounds();
	auto [bMin, bMax] = m_bird.getBoudingShape().getBounds();
	float pCenterX = pMin.x + (pMax.x - pMin.x);

	m_bird.update(dt);
	m_bird.update(dt, m_floor);

	if (pMax.x <= 0) {
		m_didInc = false;
	}

	if (!m_isGameOver && !m_didInc && bMax.x > pCenterX) {
		m_score++;
		m_text.setString(std::to_string(m_score));
		m_didInc = true;
	}

	for (auto& pipe : m_pipes) {
		m_bird.update(dt, pipe);
	}

	if (EventEmitter::peek().eventType == GameEventTypes::GAME_OVER) {
		m_isGameOver = true;
	}

	if (!m_isGameOver) {
		m_pipes.update(dt);
	}
}

void GameScene::render(sf::RenderWindow& window)
{
	window.draw(m_bg);
	m_pipes.render(window);
	m_floor.render(window);
	m_bird.render(window);
	window.draw(m_text);
}
