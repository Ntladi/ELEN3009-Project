#include <Textures.h>

Textures::Textures()
{
	initializeTexture(MapKeys::UP_PLAYER, "Assets/Player1.png");
	initializeTexture(MapKeys::DOWN_PLAYER, "Assets/Player2.png");
	initializeTexture(MapKeys::UP_ALIEN, "Assets/Alien1.png");
	initializeTexture(MapKeys::DOWN_ALIEN, "Assets/Alien2.png");
	initializeTexture(MapKeys::UP_PLAYER_BULLET, "Assets/Player1Bullet.png");
	initializeTexture(MapKeys::DOWN_PLAYER_BULLET, "Assets/Player2Bullet.png");
	initializeTexture(MapKeys::UP_PIERCER_BULLET, "Assets/Player1Bullet.png");
	initializeTexture(MapKeys::DOWN_PIERCER_BULLET, "Assets/Player2Bullet.png");
	initializeTexture(MapKeys::UP_ALIEN_BULLET, "Assets/Alien1Bullet.png");
	initializeTexture(MapKeys::DOWN_ALIEN_BULLET, "Assets/Alien2Bullet.png");
	initializeTexture(MapKeys::UP_PLAYER_LIFE, "Assets/Player_Life.png");
	initializeTexture(MapKeys::DOWN_PLAYER_LIFE, "Assets/Player_Life.png");
}

map_of_texture_ptrs Textures::getTextureMap()
{
	return textures_;
}

void Textures::initializeTexture(MapKeys key, std::string fileString)
{
	auto temp_texture = std::make_shared<sf::Texture>();
	temp_texture->loadFromFile(fileString);
	textures_.insert(std::pair<MapKeys,texture_ptr>(key,temp_texture));
}
