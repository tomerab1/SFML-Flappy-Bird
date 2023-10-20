#include "../header/Application.h"

#include "../header/Globals.h"
#include "../header/Bird.h"
#include "../header/ResourceLocator.h"

#include <iostream>

Application::Application(const sf::VideoMode& vMode, const std::string& path) : m_window{ vMode, path }
{
}

int Application::exec()
{
	try {
		m_window.setFramerateLimit(60);
		sf::Clock clock;

		sf::Texture texture;
		texture.loadFromFile(R"(.\Res\Flappy Bird Assets\Player\bird3.png)");

		Bird bird({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }, texture);

		while (m_window.isOpen()) {
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

			float dt = clock.restart().asSeconds();

			bird.update(dt);

			m_window.clear(sf::Color::Black);

			bird.render(m_window);

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
