#include <Backgrounds.h>

Backgrounds::Backgrounds()
{
	setTextures();
	setShapes();
}

void Backgrounds::setTextures()
{
	splashScreen_texture_ = std::make_shared<sf::Texture>();
	splashScreen_texture_->loadFromFile("Assets/SplashScreen.jpg");

	backgroundScreen_texture_ = std::make_shared<sf::Texture>();
	backgroundScreen_texture_->loadFromFile("Assets/BackgroundScreen.jpg");

	gameOverScreen_texture_ = std::make_shared<sf::Texture>();
	gameOverScreen_texture_->loadFromFile("Assets/GameOverScreen.jpg");
}

void Backgrounds::setShapes()
{
	splashScreen_.setSize(sf::Vector2f(Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH));
	splashScreen_.setTexture(&(*splashScreen_texture_));

	backgroundScreen_.setSize(sf::Vector2f(Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH));
	backgroundScreen_.setTexture(&(*backgroundScreen_texture_));

	gameOverScreen_.setSize(sf::Vector2f(Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH));
	gameOverScreen_.setTexture(&(*gameOverScreen_texture_));
}

sf::RectangleShape Backgrounds::getSplashScreen() const
{
	return splashScreen_;
}

sf::RectangleShape Backgrounds::getGameOverScreen() const
{
	return gameOverScreen_;
}

sf::RectangleShape Backgrounds::getBackgroundScreen() const
{
	return backgroundScreen_;
}

