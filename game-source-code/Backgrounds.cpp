#include <Backgrounds.h>

Backgrounds::Backgrounds()
{
	setTextures();
	setShapes();
}

void Backgrounds::setTextures()
{
	splash_screen_texture_ = std::make_shared<sf::Texture>();
	splash_screen_texture_->loadFromFile("Assets/SplashScreen.jpg");

	background_screen_texture_ = std::make_shared<sf::Texture>();
	background_screen_texture_->loadFromFile("Assets/BackgroundScreen.jpg");

	game_over_screen_texture_ = std::make_shared<sf::Texture>();
	game_over_screen_texture_->loadFromFile("Assets/GameOverScreen.jpg");

	game_won_screen_texture_ = std::make_shared<sf::Texture>();
	game_won_screen_texture_->loadFromFile("Assets/GameWonScreen.jpg");
}

void Backgrounds::setShapes()
{
	splash_screen_.setSize(sf::Vector2f(Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH));
	splash_screen_.setTexture(&(*splash_screen_texture_));

	background_screen_.setSize(sf::Vector2f(Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH));
	background_screen_.setTexture(&(*background_screen_texture_));

	game_over_screen_.setSize(sf::Vector2f(Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH));
	game_over_screen_.setTexture(&(*game_over_screen_texture_));

	game_won_screen_.setSize(sf::Vector2f(Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH));
	game_won_screen_.setTexture(&(*game_won_screen_texture_));
}

sf::RectangleShape Backgrounds::getSplashScreen() const
{
	return splash_screen_;
}

sf::RectangleShape Backgrounds::getGameOverScreen() const
{
	return game_over_screen_;
}

sf::RectangleShape Backgrounds::getBackgroundScreen() const
{
	return background_screen_;
}

sf::RectangleShape Backgrounds::getGameWonScreen() const
{
	return game_won_screen_;
}

