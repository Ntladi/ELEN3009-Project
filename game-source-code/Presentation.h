#ifndef PRESENTATION_H_
#define PRESENTATION_H_
#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "ScreenStates.h"
#include "GameModes.h"
#include "PlayerInputHandler.h"
#include "WindowHandler.h"
#include "Score.h"
#include <memory>
#include <map>
using map_of_two_floats = std::map<ObjectType,two_floats>;
using window_ptr = std::shared_ptr<sf::RenderWindow>;
using text_ptr = std::shared_ptr<sf::Text>;

class Presentation {
public:
	Presentation();
	void initializeSpriteSizes(const map_of_two_floats &sizes);
	void drawObject(const ObjectType &object, const Orientation &orientation,
			const two_floats &positions);
	void drawScore(const int & score);
	void clearWindow();
	bool isWindowOpen();
	void displayWindow();
	void setGameOver();
	void setGameWon();
	std::vector<bool> checkInputs();
	bool isPlaying() const;

private:
	Sprites sprites_;
	window_ptr window_;
	PlayerInputHandler player_input_handler_;
	WindowHandler window_handler_;
	Score score_;
	ScreenStates screen_state_;
	GameModes game_mode_;
	void checkPressed();
	void multiPlayerInputs();
	void singlePlayerMirroredInputs();
	void singlePlayerInvertedInputs();
	void resetInputs();
	void drawHighScore();
};

#endif
