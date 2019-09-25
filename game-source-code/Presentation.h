#ifndef PRESENTATION_H_
#define PRESENTATION_H_
#include <GameMode.h>
#include <ScreenState.h>
#include <SFML/Graphics.hpp>
#include "Sprites.h"
#include "PlayerInputHandler.h"
#include "WindowHandler.h"
#include "Score.h"
#include <memory>
#include <map>
using two_floats = std::tuple<float, float>;
using map_of_two_floats = std::map<ObjectType,two_floats>;
using window_ptr = std::shared_ptr<sf::RenderWindow>;
using text_ptr = std::shared_ptr<sf::Text>;

/** \class Presentation
 * \brief This class is the main class of the presentation layer. The class
 * receives information from the Logic class in order to manage what the player
 * actually sees on screen.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Presentation {
public:
	/** \brief Default Presentation constructor. Sets the screen state and
	 * creates a new render window.
	 */
	Presentation();

	/** \brief This method receives a constant map containing the sizes of all game objects
	 * and applies those sizes to all sprite objects through the Sprites class.
	 * \param sizes of type std::map<ObjectType, std::tuple<float, float> >
	 */
	void initializeSpriteSizes(const map_of_two_floats &sizes);

	/** \brief This method receives constant strongly typed enums of type ObjectType and
	 * Orientation as well a constant tuple of two floats. It then uses this information
	 * to draw a sprite on the window through the Sprites class.
	 * \param object of type ObjectType
	 * \param orientation of type Orientation
	 * \param position of type Orientation std::tuple<float, float>
	 */
	void drawObject(const ObjectType &object, const Orientation &orientation,
			const two_floats &position);

	/** \brief This method receives the current player score which is of type
	 * constant int from the Logic class. It then draws the score on the window
	 *  through the Score class.
	 *  \param score of type const int
	 */
	void drawScore(const int & score);

	/** \brief This method is called by the Logic class to clear the render window.
	 */
	void clearWindow();

	/** \brief This method is called by the Logic class to query if a window is
	 *  still open.
	 *  No modifications are are made to member variables.
	 *  \return bool
	 */
	bool isWindowOpen() const;

	/** \brief This method is called by the Logic class to display the render window.
	 */
	void displayWindow();
	/** \brief This method is called by the Logic class to set the screen state to
	 *  game over
	 */
	void setGameOver();

	/** \brief This method is called by the Logic class to set the screen state to
	 * game won.
	 */
	void setGameWon();

	/** \brief This method returns a constant vector containing all player inputs of
	 * type bool to the Logic class.
	 * \return std::vector<bool>
	 */
	std::vector<bool> checkInputs();

	/** \brief This method returns true if the current screen state is the game screen.
	 * \return bool
	 * No modifications are are made to member variables.
	 */
	bool isPlaying() const;

private:
	Sprites sprites_;
	window_ptr window_;
	PlayerInputHandler player_input_handler_;
	WindowHandler window_handler_;
	Score score_;
	ScreenState screen_state_;
	GameMode game_mode_;

	/** \brief This method sets the game mode depending on which key is pressed while
	 * the splash screen is displayed. It also closes the window if the correct key is
	 * pressed.
	 */
	void setMode();
};

#endif
