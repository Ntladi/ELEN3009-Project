#include <Sprites.h>

Sprites::Sprites()
{
	upPlayer_ = std::make_shared<sf::RectangleShape>();
	downPlayer_ = std::make_shared<sf::RectangleShape>();
	upAlien_ = std::make_shared<sf::RectangleShape>();
	downAlien_ = std::make_shared<sf::RectangleShape>();
	upPlayerBullet_ = std::make_shared<sf::RectangleShape>();
	downPlayerBullet_ = std::make_shared<sf::RectangleShape>();
	upAlienBullet_ = std::make_shared<sf::RectangleShape>();
	downAlienBullet_ = std::make_shared<sf::RectangleShape>();
	upPlayer_life_ = std::make_shared<sf::RectangleShape>();
	downPlayer_life_ = std::make_shared<sf::RectangleShape>();
}

void Sprites::moveSprite(const ObjectType &object,
		const Orientation &orientation, const two_floats &position)
{
	switch (object)
	{
	case ObjectType::PLAYER:
		moveSpriteObject(upPlayer_,downPlayer_,orientation,position);
		break;
	case ObjectType::ALIEN:
		moveSpriteObject(upAlien_,downAlien_,orientation,position);
		break;
	case ObjectType::PLAYER_BULLET:
		moveSpriteObject(upPlayerBullet_,downPlayerBullet_,orientation,position);
		break;
	case ObjectType::ALIEN_BULLET:
		moveSpriteObject(upAlienBullet_,downAlienBullet_,orientation,position);
		break;
	default:
		break;
	}
}


void Sprites::moveSpriteObject(sprite_ptr & upSprite, sprite_ptr & downSprite, const Orientation &orientation, const two_floats &position)
{
	float x_position, y_position;
	std::tie(x_position, y_position) = position;

	if (orientation == Orientation::FACE_UP)
	{
		upSprite->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = upSprite;
	}
	else if (orientation == Orientation::FACE_DOWN)
	{
		downSprite->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = downSprite;
	}
}

void Sprites::drawLatestObject(std::shared_ptr<sf::RenderWindow> &window)
{
	window->draw(*latestObject_);
}

void Sprites::setInitialSizes(const vec_of_two_floats &sizes)
{
	auto sprites = getSprites();
	sprite_factory_.setInitialSizes(sizes,sprites);
	sprite_factory_.applyTextures(sprites);
}

vec_of_sprite_ptrs Sprites::getSprites()
{
	return
	{	upPlayer_, downPlayer_,upAlien_,downAlien_,upPlayerBullet_,downPlayerBullet_,upAlienBullet_,downAlienBullet_};
}
