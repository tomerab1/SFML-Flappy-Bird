#pragma once

enum class GameEventTypes { GAME_START, GAME_OVER, GAME_PAUSED, GAME_NONE };

struct GameEvent {
	GameEventTypes eventType;
};
