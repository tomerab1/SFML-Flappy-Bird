#pragma once

#include <cinttypes>

constexpr uint32_t SCREEN_WIDTH = 1920;
constexpr uint32_t SCREEN_HEIGHT = 1080;

constexpr float WORLD_GRAVITY = 0.25f;

enum class CollisionType {
	UP,
	BOTTOM,
	TOP_PIPE,
	BOTTOM_PIPE,
	NONE
};