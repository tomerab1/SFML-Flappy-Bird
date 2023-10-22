#pragma once

#include "Pipe.h"

#include <random>
#include <deque>

class PipeContainer
{
public:
	using container_type = std::deque<Pipe>;

	PipeContainer();

	void render(sf::RenderWindow& window);
	void update(float dt);

	container_type::iterator begin();
	container_type::iterator end();

private:
	void generatePipes(int xOffset=0);

private:
	container_type m_pipes;
};

