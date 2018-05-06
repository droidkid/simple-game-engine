#pragma once


namespace GameObjectTypes {
	const int BALL = 1;
	const int TILE = 2;
  const int GROUND = 3;
}

namespace GameEvents {
    const int BALL_HIT_GROUND = 1;
    const int BALL_HIT_TILE = 2;
    const int BALL_HIT_ENEMY = 3;
}

namespace GameConstants {
	const int SCREEN_WIDTH = 225;
	const int SCREEN_HEIGHT =  400;
	const int FONT_SIZE_PT = 15;
	const int BALL_RADIUS = 15;
	const int TILE_WIDTH = 50;
	const int TILE_HEIGHT = 20;
	const int DURATION_BETWEEN_BRICKS = 1000;
	const int DURATION_GAME_OVER_SCREEN = 5000;
	const double MAX_BALL_VEL = 0.7;
	const double MAX_BALL_ACCEL = 0.001;
}

namespace GameState {
	const int PRE_START = 1;
	const int IN_GAME = 2;
	const int GAME_OVER = 3;
}
