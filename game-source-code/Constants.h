#ifndef CONSTANTS_H_
#define CONSTANTS_H_

struct Constants
{
public:
	const static constexpr float SCALE = 2;
	const static constexpr float SCREEN_X_LENGTH = 960*SCALE;
	const static constexpr float SCREEN_Y_LENGTH = 500*SCALE;

	const static constexpr float PLAYER_X_LENGTH = 22*SCALE;
	const static constexpr float PLAYER_Y_LENGTH = 19*SCALE;
	const static constexpr float BULLET_X_LENGTH = 3*SCALE;
	const static constexpr float BULLET_Y_LENGTH = 3*SCALE;
	const static constexpr float PIERCER_BULLET_X_LENGTH = 3*SCALE;
	const static constexpr float PIERCER_BULLET_Y_LENGTH = 10*SCALE;
	const static constexpr float ALIEN_X_LENGTH = 15*SCALE;
	const static constexpr float ALIEN_Y_LENGTH = 19*SCALE;
	const static constexpr float GLYPH_X_LENGTH = 13*SCALE;
	const static constexpr float GLYPH_Y_LENGTH = 13*SCALE;

	const static constexpr float EDGE_STEP = 1;
	const static constexpr float PLAYER_MAXIMUM_MOVEMENT_STEP = 4*SCALE;
	const static constexpr float BULLET_MAXIMUM_MOVEMENT_STEP = 2*SCALE;
	const static constexpr float ALIEN_MAXIMUM_MOVEMENT_STEP = 1*SCALE;

	const static constexpr float PLAYER_HIT_POINTS = 3;
	const static constexpr float BULLET_HIT_POINTS = 1;
	const static constexpr float ALIEN_HIT_POINTS = 1;
	const static constexpr float GLYPH_HIT_POINTS = 1;
	const static constexpr float PIERCER_BULLET_HIT_POINTS = 3;

	const static constexpr float TIME_BETWEEN_PLAYER_SHOTS = 0.5;
	const static constexpr float TIME_BETWEEN_ALIEN_SHOTS = 2;
	const static constexpr float TIME_BEFORE_1ST_POWER_UP = 6;
	const static constexpr float TIME_BEFORE_2ND_POWER_UP = 15;
	const static constexpr float MAX_ALIEN_SHOTS_PER_ROW = 5;

	const static constexpr float PLAYER_INITAL_X_POSITION = SCREEN_X_LENGTH / 2;
	const static constexpr float ALIEN_INITAL_X_POSITION = ALIEN_X_LENGTH / 2;
	const static constexpr float ALIEN_INITAL_UP_Y_POSITION = SCREEN_Y_LENGTH / 2 - ALIEN_Y_LENGTH / 2 - 5 + PLAYER_Y_LENGTH / 2;
	const static constexpr float ALIEN_INITAL_DOWN_Y_POSITION = SCREEN_Y_LENGTH / 2 + ALIEN_Y_LENGTH / 2 + 5 + PLAYER_Y_LENGTH / 2;

	const static unsigned int MAX_ARMADA_ROWS = 4;
	const static unsigned int MAX_ARMADA_COLS = 15;
	const static constexpr float SPACE_BETWEEN_ARMADA_ROWS = 8;
	const static constexpr float SPACE_BETWEEN_ARMADA_COLS = 20;
	const static constexpr float SPACE_BETWEEN_GLYPHS = 8;

	const static constexpr float ALIEN_WORTH = 200;
	const static constexpr float PLAYER_WORTH = -200;
	const static constexpr float BULLET_WORTH = 20;

	const static constexpr float HIGH_SCORE_INITIAL_CHAR_SIZE = 42*SCALE;
	const static constexpr float HIGH_SCORE_INITIAL_X = 385*SCALE;
	const static constexpr float HIGH_SCORE_INITIAL_Y = 125*SCALE;

	const static constexpr float SCORE_CHAR_SIZE = 15*SCALE;
	const static constexpr float SCORE_INITIAL_X = 475*SCALE;
	const static constexpr float SCORE_INITIAL_Y = 0;

	const static constexpr float FINAL_SCORE_CHAR_SIZE = 22*SCALE;
	const static constexpr float FINAL_SCORE_X = 260*SCALE;

	const static constexpr float FINAL_SCORE_Y = 75*SCALE;
	const static constexpr float FINAL_HIGH_SCORE_Y = 35*SCALE;

};

#endif
