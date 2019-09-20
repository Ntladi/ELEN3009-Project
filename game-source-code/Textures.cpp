#include <Textures.h>

Textures::Textures()
{
	upPlayer_texture_ = std::make_shared<sf::Texture>();
	upPlayer_texture_->loadFromFile("Assets/Player1.png");

	downPlayer_texture_ = std::make_shared<sf::Texture>();
	downPlayer_texture_->loadFromFile("Assets/Player2.png");

	upAlien_texture_ = std::make_shared<sf::Texture>();
	upAlien_texture_->loadFromFile("Assets/Alien1.png");

	downAlien_texture_ = std::make_shared<sf::Texture>();
	downAlien_texture_->loadFromFile("Assets/Alien2.png");

	upPlayer_bullet_texture_ = std::make_shared<sf::Texture>();
	upPlayer_bullet_texture_->loadFromFile("Assets/Player1Bullet.png");

	downPlayer_bullet_texture_ = std::make_shared<sf::Texture>();
	downPlayer_bullet_texture_->loadFromFile("Assets/Player2Bullet.png");

	upPiercer_bullet_texture_ = std::make_shared<sf::Texture>();
	upPiercer_bullet_texture_->loadFromFile("Assets/Player1Bullet.png");

	downPiercer_bullet_texture_ = std::make_shared<sf::Texture>();
	downPiercer_bullet_texture_->loadFromFile("Assets/Player2Bullet.png");

	upAlien_bullet_texture_ = std::make_shared<sf::Texture>();
	upAlien_bullet_texture_->loadFromFile("Assets/Alien1Bullet.png");

	downAlien_bullet_texture_ = std::make_shared<sf::Texture>();
	downAlien_bullet_texture_->loadFromFile("Assets/Alien2Bullet.png");

	upPlayer_life_texture_ = std::make_shared<sf::Texture>();
	upPlayer_life_texture_->loadFromFile("Assets/Player_Life.png");

	downPlayer_life_texture_ = std::make_shared<sf::Texture>();
	downPlayer_life_texture_->loadFromFile("Assets/Player_Life.png");

}

vec_of_texture_ptrs Textures::getTextures()
{
	return
	{ upPlayer_texture_, downPlayer_texture_, upAlien_texture_,
			downAlien_texture_, upPlayer_bullet_texture_,
			downPlayer_bullet_texture_, upPiercer_bullet_texture_,downPiercer_bullet_texture_,upAlien_bullet_texture_,
			downAlien_bullet_texture_,upPlayer_life_texture_,downPlayer_life_texture_ };
}
