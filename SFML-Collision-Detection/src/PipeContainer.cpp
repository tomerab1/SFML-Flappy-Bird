#include "../header/PipeContainer.h"

#include "../header/Globals.h"
#include "../header/ResourceLocator.h"

#include <iostream>

PipeContainer::PipeContainer()
{
	generatePipes();
	generatePipes(100);
}

void PipeContainer::render(sf::RenderWindow& window)
{
	for (auto& pipe : m_pipes) {
		pipe.render(window);
	}
}

void PipeContainer::update(float dt)
{
	auto [min, max] = m_pipes.front().getBoudingShape().getBounds();

	if (max.x <= 0) {
		generatePipes();

		m_pipes.pop_front();
		m_pipes.pop_front();
	}

	for (auto& pipe : m_pipes) {
		pipe.update(dt);
	}
}

PipeContainer::container_type::iterator PipeContainer::begin()
{
	return m_pipes.begin();
}

PipeContainer::container_type::iterator PipeContainer::end()
{
	return m_pipes.end();
}

void PipeContainer::generatePipes(int xOffset)
{
	int rand = std::rand() % 64;
	m_pipes.emplace_back(sf::Vector2f(SCREEN_WIDTH + xOffset, SCREEN_HEIGHT - 64 - 32 - rand), *ResourceLocator<TextureFactory>::getTexture("pipeTexture"));
	m_pipes.emplace_back(sf::Vector2f(SCREEN_WIDTH + xOffset, SCREEN_HEIGHT - 192 - rand), *ResourceLocator<TextureFactory>::getTexture("pipeTexture"), true);
}
