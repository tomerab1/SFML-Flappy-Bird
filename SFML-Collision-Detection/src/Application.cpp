#include "../header/Application.h"

#include "../header/Globals.h"
#include "../header/Bird.h"
#include "../header/GameEvent.h"
#include "../header/EventEmitter.h"
#include "../header/ResourceLocator.h"
#include "../header/GameScene.h"
#include "../header/MainMenuScene.h"
#include "../header/MainMenuScene.h"
#include "../header/GameOverScene.h"
#include "../header/Button.h"

#include <cassert>
#include <iostream>

Application::Application(const sf::VideoMode& vMode, const std::string& title) : m_window{ vMode, title, sf::Style::Close }
{
	m_window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
}

int Application::exec()
{
	try {
		loadAssets();
		EventEmitter::emit({ GameEventTypes::GAME_MENU });

		m_window.setFramerateLimit(60);
		sf::Clock clock;

		while (m_window.isOpen()) {
			handleFrameworkEvents();
			handleGameEvents();

			float dt = clock.restart().asSeconds();
			assert(!m_scenes.empty());
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
		case GameEventTypes::GAME_MENU:
			m_scenes.emplace(std::make_unique<MainMenuScene>(m_window));
			break;
		case GameEventTypes::GAME_START:
			m_scenes.emplace(std::make_unique<GameScene>());
			break;
		case GameEventTypes::GAME_PAUSED:
			break;
		case GameEventTypes::GAME_OVER:
			break;
		default:
			break;
		}
	}
	
}

void Application::loadAssets() const
{
	// Game elements
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Player\bird.png)", "birdTexture");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Background\Background.png)", "bgTexture");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Tileset\Ground.png)", "floorTexture");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Tileset\Pipes.png)", "pipeTexture");

	// Buttons
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Buttons\button_menu.png)", "btnMenu");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Buttons\button_ok.png)", "btnOk");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Buttons\button_pause.png)", "btnPause");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Buttons\button_play.png)", "btnPlay");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Buttons\button_resume.png)", "btnResume");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Buttons\button_score.png)", "btnScore");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Buttons\button_share.png)", "btnShare");

	// Labels
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Labels\instructions.png)", "labelInstructions");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Labels\label_flappy_bird.png)", "labelFlappyBird");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Labels\label_game_over.png)", "labelGameOver");
	ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\Flappy Bird Assets\Labels\label_get_ready.png)", "labelGetReady");

	// Sounds
	ResourceLocator<AudioFactory>::loadAudio(R"(.\Res\Flappy Bird Assets\Sounds\sfx_die.wav)", "dieSound");
	ResourceLocator<AudioFactory>::loadAudio(R"(.\Res\Flappy Bird Assets\Sounds\sfx_hit.wav)", "hitSound");
	ResourceLocator<AudioFactory>::loadAudio(R"(.\Res\Flappy Bird Assets\Sounds\sfx_point.wav)", "pointSound");
	ResourceLocator<AudioFactory>::loadAudio(R"(.\Res\Flappy Bird Assets\Sounds\sfx_wing.wav)", "wingSound");
	ResourceLocator<AudioFactory>::loadAudio(R"(.\Res\Flappy Bird Assets\Sounds\sfx_swooshing.wav)", "swooshSound");
}
