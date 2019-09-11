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

private:
	sf::RectangleShape splashScreen_;
	sf::RectangleShape backgroundScreen_;
	sf::RectangleShape gameOverScreen_;
	texture_ptr splashScreen_texture_;
	texture_ptr backgroundScreen_texture_;
	texture_ptr gameOverScreen_texture_;

};

#endif
