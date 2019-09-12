#ifndef CONSTANTS_H_
#define CONSTANTS_H_

struct Constants
{

public:

	const static constexpr float SCALE = 1; // 1.83  for 1080p

	const static constexpr float GAME_SPEED = 1;
	const static constexpr float SCREEN_X_LENGTH = 1050 * SCALE;
	const static constexpr float SCREEN_Y_LENGTH = 655 * SCALE;

	const static constexpr float PLAYER_X_LENGTH = 43 * SCALE;
	const static constexpr float PLAYER_Y_LENGTH = 37 * SCALE;
	const static constexpr float PLAYER_MAXIMUM_MOVEMENT_STEP = 1*GAME_SPEED;

	const static constexpr float PLAYER_INITAL_X_POSITION = SCREEN_X_LENGTH / 2;

	const static constexpr float PLAYER_BULLET_X_LENGTH = 3 * SCALE;
	const static constexpr float PLAYER_BULLET_Y_LENGTH = 18 * SCALE;
	const static constexpr float PLAYER_BULLET_MAXIMUM_MOVEMENT_STEP = 3*GAME_SPEED;

	const static constexpr float ALIEN_X_LENGTH = 29 * SCALE;
	const static constexpr float ALIEN_Y_LENGTH = 38 * SCALE;
	const static constexpr float ALIEN_MAXIMUM_MOVEMENT_STEP = 0.3*GAME_SPEED; // 0.3

	const static constexpr float ALIEN_INITAL_X_POSITION = ALIEN_X_LENGTH / 2;

	const static unsigned int MAX_ARMADA_ROWS = 3;
	const static unsigned int MAX_ARMADA_COLS = 8;
	const static constexpr float SPACE_BETWEEN_ARMADA_ROWS = 7;
	const static constexpr float SPACE_BETWEEN_ARMADA_COLS = 15;
	const static constexpr float SECONDS_BETWEEN_ALIEN_SHOTS = 0.5/GAME_SPEED;
	const static constexpr float SECONDS_BETWEEN_PLAYER_SHOTS = 0.3*GAME_SPEED;

};

#endif
