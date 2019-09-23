#ifndef CONSTANTS_H_
#define CONSTANTS_H_

struct Constants
{

public:

	const static constexpr float SCALE = 2; // 2  for 1080p

	const static constexpr float GAME_SPEED = 1;
	const static constexpr float SCREEN_X_LENGTH = 960*SCALE;
	const static constexpr float SCREEN_Y_LENGTH = 500*SCALE;

	const static constexpr float PLAYER_X_LENGTH = 43;
	const static constexpr float PLAYER_Y_LENGTH = 37;
	const static constexpr float PLAYER_MAXIMUM_MOVEMENT_STEP = 8;
	const static constexpr float PLAYER_INITAL_X_POSITION = SCREEN_X_LENGTH / 2;
	const static constexpr float PLAYER_HIT_POINTS = 3;

	const static constexpr float BULLET_X_LENGTH = 5;
	const static constexpr float BULLET_Y_LENGTH = 5;
	const static constexpr float PIERCER_BULLET_X_LENGTH = 5;
	const static constexpr float PIERCER_BULLET_Y_LENGTH = 20;
	const static constexpr float BULLET_HIT_POINTS = 1;
	const static constexpr float PIERCER_BULLET_HIT_POINTS = 3;
	const static constexpr float BULLET_MAXIMUM_MOVEMENT_STEP = 4;

	const static constexpr float TIME_BETWEEN_PLAYER_SHOTS = 1;
	const static constexpr float TIME_BETWEEN_ALIEN_SHOTS = 3;
	const static constexpr float TIME_BEFORE_1ST_POWER_UP = 6;
	const static constexpr float TIME_BEFORE_2ND_POWER_UP = 15;

	const static constexpr float ALIEN_X_LENGTH = 29;
	const static constexpr float ALIEN_Y_LENGTH = 37;
	const static constexpr float ALIEN_MAXIMUM_MOVEMENT_STEP = 2;
	const static constexpr float ALIEN_HIT_POINTS = 1;

	const static constexpr float ALIEN_INITAL_X_POSITION = ALIEN_X_LENGTH / 2;
	const static constexpr float ALIEN_INITAL_UP_Y_POSITION = SCREEN_Y_LENGTH / 2 - ALIEN_Y_LENGTH / 2 - 5 + PLAYER_Y_LENGTH / 2;
	const static constexpr float ALIEN_INITAL_DOWN_Y_POSITION = SCREEN_Y_LENGTH / 2 + ALIEN_Y_LENGTH / 2 + 5 + PLAYER_Y_LENGTH / 2;

	const static unsigned int MAX_ARMADA_ROWS = 3;
	const static unsigned int MAX_ARMADA_COLS = 8;
	const static constexpr float SPACE_BETWEEN_ARMADA_ROWS = 7;
	const static constexpr float SPACE_BETWEEN_ARMADA_COLS = 15;
	const static constexpr float MAX_ALIEN_SHOTS_PER_ROW = 3;

	const static constexpr float GLYPH_X_LENGTH = 25;
	const static constexpr float GLYPH_Y_LENGTH = 25;
	const static constexpr float GLYPH_HIT_POINTS = 1;
	const static constexpr float SPACE_BETWEEN_GLYPHS = 7;

	const static constexpr float ALIEN_WORTH = 200;
	const static constexpr float PLAYER_WORTH = -200;
	const static constexpr float BULLET_WORTH = 20;

};

#endif
