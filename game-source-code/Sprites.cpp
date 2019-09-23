#include <Sprites.h>

Sprites::Sprites()
{
	initializeSprite(MapKeys::UP_PLAYER);
	initializeSprite(MapKeys::DOWN_PLAYER);
	initializeSprite(MapKeys::UP_ALIEN);
	initializeSprite(MapKeys::DOWN_ALIEN);
	initializeSprite(MapKeys::UP_PLAYER_BULLET);
	initializeSprite(MapKeys::DOWN_PLAYER_BULLET);
	initializeSprite(MapKeys::UP_PIERCER_BULLET);
	initializeSprite(MapKeys::DOWN_PIERCER_BULLET);
	initializeSprite(MapKeys::UP_ALIEN_BULLET);
	initializeSprite(MapKeys::DOWN_ALIEN_BULLET);
	initializeSprite(MapKeys::UP_PLAYER_LIFE);
	initializeSprite(MapKeys::DOWN_PLAYER_LIFE);

}

void Sprites::displaySprite(const ObjectType &object,
		const Orientation &orientation, const two_floats &position)
{

	switch (object)
	{
	case ObjectType::PLAYER:
		moveSpriteObject(MapKeys::UP_PLAYER, MapKeys::DOWN_PLAYER, orientation,
				position);
		break;
	case ObjectType::ALIEN:
		moveSpriteObject(MapKeys::UP_ALIEN, MapKeys::DOWN_ALIEN, orientation,
				position);
		break;
	case ObjectType::PLAYER_BULLET:
		moveSpriteObject(MapKeys::UP_PLAYER_BULLET, MapKeys::DOWN_PLAYER_BULLET,
				orientation, position);
		break;
	case ObjectType::PIERCER_BULLET:
		moveSpriteObject(MapKeys::UP_PIERCER_BULLET,
				MapKeys::DOWN_PIERCER_BULLET, orientation, position);
		break;
	case ObjectType::ALIEN_BULLET:
		moveSpriteObject(MapKeys::UP_ALIEN_BULLET, MapKeys::DOWN_ALIEN_BULLET,
				orientation, position);
		break;
	case ObjectType::PLAYER_GLYPH:
		moveSpriteObject(MapKeys::UP_PLAYER_LIFE, MapKeys::DOWN_PLAYER_LIFE,
				orientation, position);
		break;
	default:
		break;
	}
}

void Sprites::moveSpriteObject(MapKeys upKey, MapKeys downKey,
		const Orientation &orientation, const two_floats &position)
{
	float x_position, y_position;
	std::tie(x_position, y_position) = position;

	if (orientation == Orientation::FACE_UP)
	{
		sprites_.at(upKey)->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = sprites_.at(upKey);
	}
	else if (orientation == Orientation::FACE_DOWN)
	{
		sprites_.at(downKey)->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = sprites_.at(downKey);
	}
}

void Sprites::drawLatestObject(std::shared_ptr<sf::RenderWindow> &window)
{
	window->draw(*latestObject_);
}

void Sprites::setInitialSizes(const map_of_two_floats & sizes)
{
	sprite_factory_.setInitialSizes(sizes,sprites_);
	sprite_factory_.applyTextures(sprites_);
}

void Sprites::initializeSprite(MapKeys key)
{
	auto temp_obj = std::make_shared<sf::RectangleShape>();
	sprites_.insert(std::pair<MapKeys, sprite_ptr>(key, temp_obj));
}
