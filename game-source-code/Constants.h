#ifndef CONSTANTS_H_
#define CONSTANTS_H_

	struct Constants {

	public:
		const static constexpr float SCREEN_X_LENGTH = 1280;
		const static constexpr float SCREEN_Y_LENGTH = 760;

		const static constexpr float PLAYER_X_LENGTH = 70;
		const static constexpr float PLAYER_Y_LENGTH = 150;
		const static constexpr float PLAYER_MAXIMUM_MOVEMENT_STEP = 4;

		const static constexpr float PLAYER_INITAL_X_POSITION = SCREEN_X_LENGTH/2;

		const static constexpr float PLAYER_BULLET_X_LENGTH = 4;
		const static constexpr float PLAYER_BULLET_Y_LENGTH = 8;
		const static constexpr float PLAYER_BULLET_MAXIMUM_MOVEMENT_STEP = 1;

		const static constexpr float ALIEN_X_LENGTH = 40;
		const static constexpr float ALIEN_Y_LENGTH = 40;
		const static constexpr float ALIEN_MAXIMUM_MOVEMENT_STEP = 1;

		const static constexpr float ALIEN_INITAL_X_POSITION = ALIEN_X_LENGTH/2;

	};



#endif
