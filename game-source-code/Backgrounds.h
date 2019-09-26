#ifndef BACKGROUNDS_H_
#define BACKGROUNDS_H_
#include <SFML/Graphics.hpp>
#include <memory>
#include "Textures.h"
#include "Constants.h"
using texture_ptr = std::shared_ptr<sf::Texture>;

/** \class Backgrounds
 * \brief This class is a data layer class that handles the backgrounds
 * displayed during the various screen states of the game. It is encapsulated
 * within the WindowHandler class.
 * \author 1599953 Ntladi Mohajane and 1705890 Tshepo Chokoe
 * \version 3.0
 */
class Backgrounds
{
public:
	/** \brief Default Backgrounds constructor.
	 */
	Backgrounds();

	/** \brief This method loads the appropriate background
	 * textures from file and also initializes the background rectangular
	 * objects to the correct size.
	 */
	void setTextures();

	/** \brief This method sets the appropriate texture to the appropriate game object
	 */
	void setShapes();
	sf::RectangleShape getSplashScreen() const;
	sf::RectangleShape getBackgroundScreen() const;
	sf::RectangleShape getGameOverScreen() const;
	sf::RectangleShape getGameWonScreen() const;

private:
	sf::RectangleShape splash_screen_;
	sf::RectangleShape background_screen_;
	sf::RectangleShape game_over_screen_;
	sf::RectangleShape game_won_screen_;
	texture_ptr splash_screen_texture_;
	texture_ptr background_screen_texture_;
	texture_ptr game_over_screen_texture_;
	texture_ptr game_won_screen_texture_;

};

#endif
