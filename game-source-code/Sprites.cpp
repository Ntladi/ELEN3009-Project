#include <Sprites.h>

Sprites::Sprites()
{
}

void Sprites::movePlayer(const Orientation &orientation, const two_floats &position)
{
	float x_position, y_position;
	std::tie(x_position, y_position) = position;

	if (orientation == Orientation::FACE_UP)
	{
		upPlayer_.setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = upPlayer_;
	}
	else if (orientation == Orientation::FACE_DOWN)
	{
		downPlayer_.setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = downPlayer_;
	}
}

void Sprites::moveAlien(const Orientation &orientation, const two_floats &position)
{
	float x_position, y_position;
	std::tie(x_position, y_position) = position;

	if (orientation == Orientation::FACE_UP)
	{
		upAlien_.setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = upAlien_;
	}
	else if (orientation == Orientation::FACE_DOWN)
	{
		downAlien_.setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = downAlien_;
	}
}

void Sprites::movePlayerBullet(const Orientation &orientation, const two_floats &position)
{
	float x_position, y_position;
	std::tie(x_position, y_position) = position;

	if (orientation == Orientation::FACE_UP)
	{
		upPlayerBullet_.setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = upPlayerBullet_;
	}
	else if (orientation == Orientation::FACE_DOWN)
	{
		downPlayerBullet_.setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = downPlayerBullet_;
	}
}

void Sprites::moveAlienBullet(const Orientation &orientation, const two_floats &position)
{
	float x_position, y_position;
	std::tie(x_position, y_position) = position;
	if (orientation == Orientation::FACE_UP)
	{
		upAlienBullet_.setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = upAlienBullet_;
	}
	else if (orientation == Orientation::FACE_DOWN)
	{
		downAlienBullet_.setPosition(sf::Vector2f(x_position, y_position));
		latestObject_ = downAlienBullet_;
	}

}


void Sprites::drawLatestObject(std::shared_ptr<sf::RenderWindow> &window)
{
	window->draw(latestObject_);
}

void Sprites::setInitialSizes(const vec_of_two_floats &sizes)
{
	float x_size;
	float y_size;

	std::tie(x_size, y_size) = sizes.at(0);
	upPlayer_.setSize(sf::Vector2f(x_size, y_size));
	upPlayer_.setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	downPlayer_.setSize(sf::Vector2f(x_size, y_size));
	downPlayer_.setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	downPlayer_.setRotation(180.0f);

	std::tie(x_size, y_size) = sizes.at(1);
	upAlien_.setSize(sf::Vector2f(x_size, y_size));
	upAlien_.setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	downAlien_.setSize(sf::Vector2f(x_size, y_size));
	downAlien_.setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	downAlien_.setRotation(180.0f);

	std::tie(x_size, y_size) = sizes.at(2);
	upPlayerBullet_.setSize(sf::Vector2f(x_size, y_size));
	upPlayerBullet_.setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	downPlayerBullet_.setSize(sf::Vector2f(x_size, y_size));
	downPlayerBullet_.setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	downPlayerBullet_.setRotation(180.0f);
	upAlienBullet_.setSize(sf::Vector2f(x_size, y_size));
	upAlienBullet_.setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	downAlienBullet_.setSize(sf::Vector2f(x_size, y_size));
	downAlienBullet_.setOrigin(sf::Vector2f(x_size / 2, y_size / 2));
	downAlienBullet_.setRotation(180.0f);

	applyTextures();
}

void Sprites::applyTextures()
{
	upPlayer_.setTexture(&(*(textures_.getTextures().at(0))));
	downPlayer_.setTexture(&(*(textures_.getTextures().at(1))));
	upAlien_.setTexture(&(*(textures_.getTextures().at(2))));
	downAlien_.setTexture(&(*(textures_.getTextures().at(3))));
	upPlayerBullet_.setTexture(&(*(textures_.getTextures().at(4))));
	downPlayerBullet_.setTexture(&(*(textures_.getTextures().at(5))));
	upAlienBullet_.setTexture(&(*(textures_.getTextures().at(6))));
	downAlienBullet_.setTexture(&(*(textures_.getTextures().at(7))));
}
