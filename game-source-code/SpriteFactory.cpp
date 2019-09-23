#include <SpriteFactory.h>

void SpriteFactory::setInitialSizes(const map_of_two_floats &sizes,
		map_of_sprite_ptrs &sprites)
{
	setSize(sizes, sprites, MapKeys::UP_PLAYER, MapKeys::DOWN_PLAYER,
			ObjectType::PLAYER, true);

	setSize(sizes, sprites, MapKeys::UP_ALIEN, MapKeys::DOWN_ALIEN,
			ObjectType::ALIEN, true);

	setSize(sizes, sprites, MapKeys::UP_PLAYER_BULLET, MapKeys::DOWN_PLAYER_BULLET,
			ObjectType::PLAYER_BULLET, true);

	setSize(sizes, sprites, MapKeys::UP_PIERCER_BULLET, MapKeys::DOWN_PIERCER_BULLET,
			ObjectType::PIERCER_BULLET, true);

	setSize(sizes, sprites, MapKeys::UP_ALIEN_BULLET, MapKeys::DOWN_ALIEN_BULLET,
			ObjectType::PLAYER_BULLET, true);

	setSize(sizes, sprites, MapKeys::UP_PLAYER_LIFE, MapKeys::DOWN_PLAYER_LIFE,
			ObjectType::PLAYER_GLYPH, false);
}

void SpriteFactory::applyTextures(map_of_sprite_ptrs &sprites)
{
	for(auto &i:sprites)
		i.second->setTexture(&(*(textures_.getTextureMap().at(i.first))));
}

void SpriteFactory::setSize(const map_of_two_floats &sizes,
		map_of_sprite_ptrs &sprites, MapKeys up_object, MapKeys down_object,
		ObjectType size_key, bool flip_down)
{
	auto [x_size, y_size] = sizes.at(size_key);

	sprites.at(up_object)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(up_object)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));

	sprites.at(down_object)->setSize(sf::Vector2f(x_size, y_size));
	sprites.at(down_object)->setOrigin(sf::Vector2f(x_size / 2, y_size / 2));

	if(flip_down)
		sprites.at(down_object)->setRotation(180.0f);
}
