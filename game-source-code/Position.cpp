#include <Position.h>

Position::Position(ObjectType object, Orientation orientation)
{
	if (object == ObjectType::PLAYER)
		initializePlayerPosition(orientation);

	else if (object == ObjectType::ALIEN_BULLET
			|| object == ObjectType::PLAYER_BULLET)
		initializeBulletPosition(orientation);

	else if (object == ObjectType::ALIEN)
		initializeAliePosition(orientation);
}

void Position::setXPosition(const float &x)
{
	x_position_ = x;
}

void Position::setYPosition(const float &y)
{
	y_position_ = y;
}

float Position::getXPosition() const
{
	return x_position_;
}

float Position::getYPosition() const
{
	return y_position_;
}

void Position::initializePlayerPosition(Orientation &orientation)
{
	x_position_ = Constants::PLAYER_INITAL_X_POSITION;

	if (orientation == Orientation::FACE_UP)
		y_position_ = Constants::SCREEN_Y_LENGTH
				- Constants::PLAYER_Y_LENGTH/2;
	else if (orientation == Orientation::FACE_DOWN)
		y_position_ = Constants::PLAYER_Y_LENGTH*1.5;
}

void Position::initializeBulletPosition(Orientation &orientation)
{
	x_position_ = 0;

	if (orientation == Orientation::FACE_UP)
		y_position_ = -(Constants::PLAYER_BULLET_Y_LENGTH / 2)
				- Constants::PLAYER_BULLET_Y_LENGTH;
	else if (orientation == Orientation::FACE_DOWN)
		y_position_ = (Constants::PLAYER_BULLET_Y_LENGTH / 2)
				+ Constants::PLAYER_BULLET_Y_LENGTH;
}

void Position::initializeAliePosition(Orientation &orientation)
{
	x_position_ = Constants::ALIEN_INITAL_X_POSITION;

	if (orientation == Orientation::FACE_UP)
		y_position_ = Constants::SCREEN_Y_LENGTH / 2
				- Constants::ALIEN_Y_LENGTH / 2 - 5 + Constants::PLAYER_Y_LENGTH/2;
	else if (orientation == Orientation::FACE_DOWN)
		y_position_ = Constants::SCREEN_Y_LENGTH / 2
				+ Constants::ALIEN_Y_LENGTH / 2 + 5 + Constants::PLAYER_Y_LENGTH/2;
}
