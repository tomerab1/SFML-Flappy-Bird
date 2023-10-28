#pragma once

enum class GameEventTypes { GAME_MENU, GAME_START, GAME_SCENE_OVER, GAME_OVER, GAME_RESTART, GAME_NONE };

struct GameEvent {
	GameEventTypes eventType;
};
