#ifndef PRESENTATION_H_
#define PRESENTATION_H_
#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "Backgrounds.h"
#include "StopWatch.h"
#include "ScreenStates.h"
#include "GameModes.h"
#include "PlayerInputHandler.h"
#include <memory>
using window_ptr = std::shared_ptr<sf::RenderWindow>;

class Presentation {
public:
	Presentation();
	void createWindow();
	void initializeSpriteSizes(const vec_of_two_floats &sizes);
	void initializeSpritePositions(const vec_of_two_floats &sizes);
	void displaySprite(const ObjectType &object, const Orientation &orientation,
			const two_floats &positions);
	void clearWindow();
	bool isWindowOpen();
	void displayWindow();
	void setGameOver();
	void setGameWon();
	std::vector<bool> checkInputs();
	bool isPlaying() const;

private:
	void events();
	Sprites sprites_;
	Backgrounds backgrounds_;
	window_ptr window_;
	PlayerInputHandler player_input_handler_;
	ScreenStates screen_state_;
	GameModes game_mode_;
	void checkPressed();
	void multiPlayerInputs();
	void singlePlayerMirroredInputs();
	void singlePlayerInvertedInputs();
	void resetInputs();
};

#endif
