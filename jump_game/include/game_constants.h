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
	const int FONT_SIZE_PT = 28;
}

namespace GameState {
	const int PRE_START = 1;
	const int IN_GAME = 2;
	const int GAME_OVER = 3;
}
