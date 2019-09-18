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
}

void Sprites::movePlayer(const Orientation &orientation,
		const two_floats &position)
{
	float x_position, y_position;
	std::tie(x_position, y_position) = position;

	if (orientation == Orientation::FACE_UP)
	{
		upPlayer_->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = upPlayer_;
	}
	else if (orientation == Orientation::FACE_DOWN)
	{
		downPlayer_->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = downPlayer_;
	}
}

void Sprites::moveAlien(const Orientation &orientation,
		const two_floats &position)
{
	float x_position, y_position;
	std::tie(x_position, y_position) = position;

	if (orientation == Orientation::FACE_UP)
	{
		upAlien_->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = upAlien_;
	}
	else if (orientation == Orientation::FACE_DOWN)
	{
		downAlien_->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = downAlien_;
	}
}

void Sprites::movePlayerBullet(const Orientation &orientation,
		const two_floats &position)
{
	float x_position, y_position;
	std::tie(x_position, y_position) = position;

	if (orientation == Orientation::FACE_UP)
	{
		upPlayerBullet_->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = upPlayerBullet_;
	}
	else if (orientation == Orientation::FACE_DOWN)
	{
		downPlayerBullet_->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = downPlayerBullet_;
	}
}

void Sprites::moveAlienBullet(const Orientation &orientation,
		const two_floats &position)
{
	float x_position, y_position;
	std::tie(x_position, y_position) = position;
	if (orientation == Orientation::FACE_UP)
	{
		upAlienBullet_->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = upAlienBullet_;
	}
	else if (orientation == Orientation::FACE_DOWN)
	{
		downAlienBullet_->setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = downAlienBullet_;
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
