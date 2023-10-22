#pragma once

#include <cinttypes>

constexpr uint32_t SCREEN_WIDTH = 180;
constexpr uint32_t SCREEN_HEIGHT = 320;
constexpr uint32_t SCREEN_RESIZE = 2;

constexpr int BIRD_WIDTH = 32;

constexpr float WORLD_GRAVITY = 0.35f;

enum class CollisionType {
	UP,
	BOTTOM,
	TOP_PIPE,
	BOTTOM_PIPE,
	NONE
};