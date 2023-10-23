#include "../header/Application.h"

#include "../header/Globals.h"
#include "../header/Bird.h"
#include "../header/GameEvent.h"
#include "../header/EventEmitter.h"
#include "../header/ResourceLocator.h"
#include "../header/GameScene.h"

#include <cassert>
#include <iostream>

Application::Application(const sf::VideoMode& vMode, const std::string& title) : m_window{ vMode, title, sf::Style::Close }
{
	m_window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
	loadAssets();
	m_scenes.emplace(std::make_unique<GameScene>());
}

int Application::exec()
{
	try {
		m_window.setFramerateLimit(60);
		sf::Clock clock;

		while (m_window.isOpen()) {
			assert(m_scenes.size() != 0);
			float dt = clock.restart().asSeconds();

			handleFrameworkEvents();
			handleGameEvents();

			m_scenes.top()->update(dt);

			m_window.clear(sf::Color::Black);
			m_scenes.top()->render(m_window);
			m_window.display();
		}

		return EXIT_SUCCESS;
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << '\n';
		return EXIT_FAILURE;
	}
	catch (...) {
		std::cout << "Unknown error occurred" << '\n';
		return EXIT_FAILURE;
	}
}

void Application::handleFrameworkEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			break;
		}
	}
}

void Application::handleGameEvents()
{
	GameEvent gEvent;
	while (EventEmitter::pollEvent(gEvent)) {
		switch (gEvent.eventType) {
		default:
			break;
		}
	}
	
}

void Application::loadAssets() const
{
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Player\bird.png)", "birdTexture");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Background\Background.png)", "bgTexture");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Tileset\Ground.png)", "floorTexture");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Tileset\Pipes.png)", "pipeTexture");
}
