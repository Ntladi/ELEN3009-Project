#ifndef BACKGROUNDS_H_
#define BACKGROUNDS_H_
#include <SFML/Graphics.hpp>
#include <memory>
#include "Textures.h"
#include "Constants.h"
using texture_ptr = std::shared_ptr<sf::Texture>;

class Backgrounds
{
public:
	Backgrounds();
	void setTextures();
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
